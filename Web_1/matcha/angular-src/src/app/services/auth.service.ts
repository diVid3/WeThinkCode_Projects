import { Injectable } from '@angular/core';
import { HttpHeaders } from '@angular/common/http';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  authToken: any;
  user: any;

  constructor(private http: HttpClient) { }

  // This returns an observable that needs to be subscribed to, which is done in onRegisterSubmit()
  // in register.component.ts
  registerUser(user) {
    let regHeader = new HttpHeaders;
    regHeader.set('Content-Type', 'application/json');
    return this.http.post('http://localhost:3000/user/register', user, {headers: regHeader});
  }

  // This returns an observable that needs to be subscribed to, which is done in onLoginSubmit()
  // in login.component.ts
  authenticateUser(user) {
    let authHeader = new HttpHeaders;
    authHeader.set('Content-Type', 'application/json');
    return this.http.post('http://localhost:3000/user/authenticate', user, {headers: authHeader});
  }

  // Token needs to be send along here, because protected route on backend, hence loadToken().
  // This can only be called once a token is available to be retrieved, i.e. after login.
  // This is ridiculous... Setting or appending headers will not result in authentication at
  // the backend................................ One needs to set headers via the constructor.
  // However .set() seems to work with requests not requiring authorization?
  // 
  // This returns an observable that needs to be subscribed to, which is done in ngOnInit()
  // in profile.component.ts
  getProfile() {
    this.loadToken();

    // This is the prefered way of setting headers.
    let httpOptions = {
      headers: new HttpHeaders({
        'Content-Type': 'application/json',
        'Authorization': this.authToken
      })
    };

    return this.http.get('http://localhost:3000/user/profile', httpOptions);
  }

  // Used to retrieve the token from localStorage. Called from getProfile() above.
  loadToken() {
    const token = localStorage.getItem('user_jwt');
    this.authToken = token;
  }

  // This does not account for expired tokens, for that you'd use { JwtModule } from '@auth0/angular-jwt'
  // in conjuction with isTokenExpired() from the same module's service. However, if you want to avoid
  // that module from attempting to send tokens with requests automatically, you can just create an
  // HTTP interceptor which will redirect the user upon receiving any 401 Unauthorized errors.
  // 
  // This is called from navbar.component.html to check in the user is logged in/has a token, it's
  // also called from canActivate() in auth.guard.ts to check whether a user is logged in/has a
  // token to allow for certain route access.
  loggedIn() {
    return !!localStorage.getItem('user_jwt');
  }

  // 'id_token is the default path JWT uses. Need to stringify as localStorage can only store strings.
  // This is done when logging in.
  // 
  // This is called from onLoginSubmit() in login.component.ts in order to store the token and user
  // data that has been received from the backend. onLoginSubmit() ->
  // authService.authenticateUser(user).subscribe(data => { ... }) -> authService.storeUserData().
  storeUserData(token, user) {
    localStorage.setItem('user_jwt', token);
    localStorage.setItem('user', JSON.stringify(user));
    this.authToken = token;
    this.user = user;
  }

  // This simply unsets the tokens when the user clicks on logout in navbar.component.html.
  logout() {
    this.authToken = null;
    this.user = null;
    localStorage.clear();
  }
}
