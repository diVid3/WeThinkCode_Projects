import { Injectable } from '@angular/core';
import { HttpHeaders } from '@angular/common/http';
import { HttpClient, HttpParams,
  HttpRequest, HttpEvent } from '@angular/common/http';
import { Observable } from 'rxjs';
import { PipeCollector } from '@angular/compiler/src/template_parser/binding_parser';

@Injectable({
  providedIn: 'root'
})
export class EditService {

  constructor(private http: HttpClient) { }

  // editProfileData(editedUser) {
  //   let httpOptions = {
  //     headers: new HttpHeaders({
  //       'Content-Type': 'application/json',
  //       'Authorization': localStorage.getItem('user_jwt')
  //     })
  //   };

  //   return this.http.post('http://localhost:3000/user/authenticate',
  //   editedUser, httpOptions);
  // }
  
  // file from event.target.files[0].
  // editProfile(user: any, files: File):Observable<HttpEvent<any>> {
  editProfile(user: any, avatarArr: Array<File>,
    pictureArr: Array<File>):Observable<HttpEvent<any>> {
    let formData = new FormData();
    let params = new HttpParams();
    const options = {
      // Might need to add token header here.
      params: params
    };

    formData.append('updatedUserProfile', user);

    if (avatarArr)
      formData.append('pictures', avatarArr[0], avatarArr[0]['name']);
    // formData.append('avatar', avatarArr[0]);

    if (pictureArr) {
      let pictureArrLength = pictureArr.length;
      for (let i = 0; i < pictureArrLength; i++) {
        // formData.append(`picture${i}`, pictureArr[i]);
        formData.append('pictures', pictureArr[i], pictureArr[i]['name']);
      }
    }

    const request = new HttpRequest('POST',
      'http://localhost:3000/user/edit', formData, options);
    return this.http.request(request);
  }
}
