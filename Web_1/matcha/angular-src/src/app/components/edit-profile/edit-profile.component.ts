import { Component, OnInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';

@Component({
  selector: 'app-edit-profile',
  templateUrl: './edit-profile.component.html',
  styleUrls: ['./edit-profile.component.css']
})
export class EditProfileComponent implements OnInit {

  user: Object;

  long: number;
  lat: number;

  // Interest Button Conditions. This is to circumvent the fact that native
  // classes are not applied in the presence of angular class binding.
  btn: boolean = true;
  marginTagButton: boolean = true;

  // Button Class Variables.
  btnShow0: boolean;
  btnShow1: boolean;
  btnShow2: boolean;
  btnShow3: boolean;
  btnShow4: boolean;
  btnShow5: boolean;
  btnShow6: boolean;
  btnShow7: boolean;
  btnShow8: boolean;
  btnShow9: boolean;

  constructor(private authService: AuthService) { }

  ngOnInit() {
    this.authService.getProfile().subscribe(profile => {
      this.user = (<any>profile).user;
      this.long = (<any>this.user).ipinfoLoc.coordinates[0];
      this.lat = (<any>this.user).ipinfoLoc.coordinates[1];

      // Detecting Interest/Tag States
      this.btnShow0 = (<any>this.user).interests.includes('Matcha');
      this.btnShow1 = (<any>this.user).interests.includes('Sports');
      this.btnShow2 = (<any>this.user).interests.includes('Art');
      this.btnShow3 = (<any>this.user).interests.includes('Gaming');
      this.btnShow4 = (<any>this.user).interests.includes('Traveling');
      this.btnShow5 = (<any>this.user).interests.includes('Music');
      this.btnShow6 = (<any>this.user).interests.includes('Cooking');
      this.btnShow7 = (<any>this.user).interests.includes('Reading');
      this.btnShow8 = (<any>this.user).interests.includes('Computers');
      this.btnShow9 = (<any>this.user).interests.includes('Movies');
    },
    err => {
      console.log(err);
      return false;
    });
  }

  removeInterest(interest, btnNum) {
    let stringIndex = (<any>this.user).interests.indexOf(interest);
    (<any>this.user).interests.splice(stringIndex, 1);
    if (btnNum == "tag0") this.btnShow0 = false;
    if (btnNum == "tag1") this.btnShow1 = false;
    if (btnNum == "tag2") this.btnShow2 = false;
    if (btnNum == "tag3") this.btnShow3 = false;
    if (btnNum == "tag4") this.btnShow4 = false;
    if (btnNum == "tag5") this.btnShow5 = false;
    if (btnNum == "tag6") this.btnShow6 = false;
    if (btnNum == "tag7") this.btnShow7 = false;
    if (btnNum == "tag8") this.btnShow8 = false;
    if (btnNum == "tag9") this.btnShow9 = false;
  }

  addInterest(interest, btnNum) {
    (<any>this.user).interests.push(interest);
    if (btnNum == "tag0") this.btnShow0 = true;
    if (btnNum == "tag1") this.btnShow1 = true;
    if (btnNum == "tag2") this.btnShow2 = true;
    if (btnNum == "tag3") this.btnShow3 = true;
    if (btnNum == "tag4") this.btnShow4 = true;
    if (btnNum == "tag5") this.btnShow5 = true;
    if (btnNum == "tag6") this.btnShow6 = true;
    if (btnNum == "tag7") this.btnShow7 = true;
    if (btnNum == "tag8") this.btnShow8 = true;
    if (btnNum == "tag9") this.btnShow9 = true;
  }

  toggleInterest(event) {
    let interest = event.srcElement.innerHTML;
    let btnNum = event.srcElement.id;
    if ((<any>this.user).interests.includes(interest))
      this.removeInterest(interest, btnNum);
    else
      this.addInterest(interest, btnNum);
  }
}
