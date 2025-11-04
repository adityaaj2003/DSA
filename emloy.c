package com.example.auth.controller;

import org.springframework.security.core.Authentication;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class SampleController {

    @GetMapping("/public/hello")
    public String publicHello() {
        return "Hello public!";
    }

    @GetMapping("/user/me")
    public String userInfo(Authentication auth) {
        // principal is userId (string) because filter sets it that way
        return "Authenticated user id: " + auth.getPrincipal() + ", authorities: " + auth.getAuthorities();
    }

    @GetMapping("/api/provider/hello")
    public String providerHello() {
        return "Hello provider (ROLE_PROVIDER required)";
    }

    @GetMapping("/api/admin/hello")
    public String adminHello() {
        return "Hello admin (ROLE_ADMIN required)";
    }
}
