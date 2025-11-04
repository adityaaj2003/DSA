package com.example.auth.service;

import com.example.auth.dto.*;
import com.example.auth.model.Role;
import com.example.auth.model.User;
import com.example.auth.repo.UserRepository;
import com.example.auth.security.JwtUtil;
import org.springframework.security.authentication.*;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class AuthService {

    private final UserRepository userRepository;
    private final AuthenticationManager authenticationManager;
    private final PasswordEncoder passwordEncoder;
    private final JwtUtil jwtUtil;

    public AuthService(UserRepository userRepository,
                       AuthenticationManager authenticationManager,
                       PasswordEncoder passwordEncoder,
                       JwtUtil jwtUtil) {
        this.userRepository = userRepository;
        this.authenticationManager = authenticationManager;
        this.passwordEncoder = passwordEncoder;
        this.jwtUtil = jwtUtil;
    }

    public AuthResponse register(RegisterRequest req) {
        userRepository.findByEmail(req.getEmail()).ifPresent(u -> {
            throw new RuntimeException("Email already registered");
        });

        User user = new User();
        user.setName(req.getName());
        user.setEmail(req.getEmail());
        user.setPassword(passwordEncoder.encode(req.getPassword()));
        Role role;
        try {
            role = Role.valueOf(req.getRole());
        } catch (IllegalArgumentException ex) {
            throw new RuntimeException("Invalid role. Use ROLE_CUSTOMER or ROLE_PROVIDER or ROLE_ADMIN");
        }
        user.setRole(role);
        User saved = userRepository.save(user);

        String token = jwtUtil.generateToken(saved.getId().toString(), saved.getRole().name());
        return new AuthResponse(token, saved.getId(), saved.getRole().name());
    }

    public AuthResponse login(LoginRequest req) {
        // Authenticate via AuthenticationManager to validate credentials
        try {
            authenticationManager.authenticate(
                    new UsernamePasswordAuthenticationToken(req.getEmail(), req.getPassword())
            );
        } catch (AuthenticationException ex) {
            throw new RuntimeException("Invalid credentials");
        }
        User user = userRepository.findByEmail(req.getEmail()).orElseThrow();
        String token = jwtUtil.generateToken(user.getId().toString(), user.getRole().name());
        return new AuthResponse(token, user.getId(), user.getRole().name());
    }
}
