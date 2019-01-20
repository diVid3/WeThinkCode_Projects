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

  editProfile(user: any, avatarArr: Array<File>,
    pictureArr: Array<File>):Observable<HttpEvent<any>> {
    let formData = new FormData();
    let params = new HttpParams();
    const options = {
      // headers: new HttpHeaders({
        // 'Content-Type': 'application/json', <------ This will not allow multipart form data
        // 'Accept': 'application/json' <------ This gets ignored by bodyparser.
      // }),
      // Might need to add token header here.
      params: params
    };

    formData.append('updatedUserProfile', JSON.stringify(user));

    if (avatarArr && avatarArr.length >= 1) {
      formData.append('pictures', avatarArr[0], avatarArr[0]['name']);
    }

    if (pictureArr) {
      let pictureArrLength = pictureArr.length;
      if (pictureArrLength >= 1)
        for (let i = 0; i < pictureArrLength; i++) {
          formData.append('pictures', pictureArr[i], pictureArr[i]['name']);
        }
    }

    return this.http.request(
      new HttpRequest('POST', 'http://localhost:3000/user/edit',
      formData, options)
    );
  }
}
