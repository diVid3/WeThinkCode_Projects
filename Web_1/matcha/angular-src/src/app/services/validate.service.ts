import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class ValidateService {

  constructor() { }

  // This is called from onRegisterSubmit(). This simply checks if the user filled in all the fields.
  validateRegister(user) {
    if (user.name == undefined ||
      user.email == undefined ||
      user.username == undefined ||
      user.password == undefined)
      return false;
    else
      return true;
  }

  // This is called from onRegisterSubmit(). This returns true on false, depending on whether the email is valid or not.
  validateEmail(email) {
    const re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(String(email).toLowerCase());
  }

}
