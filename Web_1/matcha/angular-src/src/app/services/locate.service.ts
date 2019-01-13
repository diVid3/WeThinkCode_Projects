import { Injectable } from '@angular/core';
import { HttpHeaders } from '@angular/common/http';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class LocateService {

  constructor(private http: HttpClient) { }

  locateUserIpinfo() {
    let httpOptions = {
      headers: new HttpHeaders({
        'Content-Type': 'application/json',
      })
    };
    return this.http.get('https://ipinfo.io/json', httpOptions)
  }

  locateUserNav() {
    
  }
}
