import { Injectable } from '@angular/core';
import { Router, CanActivate } from '@angular/router';
import { AuthService } from '../services/auth.service';

@Injectable({
  providedIn: 'root'
})
export class AuthGuard implements CanActivate {

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }
  
  // This simply checks if a user is logged in/has a token.
  // This is used in app-routing.module.ts to secure routes.
  canActivate() {
    if (this.authService.loggedIn()) {
      return true;
    }
    this.router.navigate(['/login']);
    return false;
  }
}