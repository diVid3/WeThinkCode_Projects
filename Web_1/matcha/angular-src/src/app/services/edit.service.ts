import { Injectable } from '@angular/core';
import { HttpHeaders } from '@angular/common/http';
import { HttpClient, HttpParams,
  HttpRequest, HttpEvent } from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class EditService {

  constructor(private http: HttpClient) { }

  editProfileData(editedUser) {
    let httpOptions = {
      headers: new HttpHeaders({
        'Content-Type': 'application/json',
        'Authorization': localStorage.getItem('user_jwt')
      })
    };

    return this.http.post('http://localhost:3000/user/authenticate',
    editedUser, httpOptions);
  }

  // file from event.target.files[0].
  editAvatar(url: string, file: File):Observable<HttpEvent<any>> {
    let formData = new FormData();
    let params = new HttpParams();
    const options = { params: params };

    formData.append('uploadedAvatar', file)

    const req = new HttpRequest('POST', url, formData, options);
    return this.http.request(req);
  }

  editPictures(url: string, file: File) {

  }
}
