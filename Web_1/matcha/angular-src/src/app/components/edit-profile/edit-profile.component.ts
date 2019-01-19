import { Component, OnInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { EditService } from '../../services/edit.service';

@Component({
  selector: 'app-edit-profile',
  templateUrl: './edit-profile.component.html',
  styleUrls: ['./edit-profile.component.css']
})
export class EditProfileComponent implements OnInit {

  user: Object;

  // Previous user location. Will get set to new location upon map click.
  oldLong: number;
  oldLat: number;

  // New user location.
  newLong: number;
  newLat: number;

  // Which location to use on update submit.
  useNewLocation: boolean = false;

  // Location specification state.
  specifyLocation: boolean = false;

  // Variable to keep track of interest array.
  interestArray: any;

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

  // File Select Info
  avatarArr: any;
  pictureArr: any;

  constructor(
    private authService: AuthService,
    private editService: EditService
  ) { }

  ngOnInit() {
    this.authService.getProfile().subscribe(profile => {
      this.user = (<any>profile).user;
      console.log(this.user);
      this.oldLong = (<any>this.user).ipinfoLoc.coordinates[0];
      this.oldLat = (<any>this.user).ipinfoLoc.coordinates[1];

      this.interestArray = (<any>this.user).interests;

      // Detecting Interest/Tag States.
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

  // Removes an interest from the interest array and toggles the corresponding
  // button.
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

  // Adds an interest to the interest array and toggles the corresponding
  // button.
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

  // Function to toggle interest buttons.
  toggleInterest(event) {
    let interest = event.srcElement.innerHTML;
    let btnNum = event.srcElement.id;
    if ((<any>this.user).interests.includes(interest))
      this.removeInterest(interest, btnNum);
    else
      this.addInterest(interest, btnNum);
  }

  selectAvatar(event) {
    this.avatarArr = event.target.files;
  }

  selectPictures(event) {
    this.pictureArr = event.target.files;
  }

  onLocationKeep() {
    this.specifyLocation = false;
    this.useNewLocation = false;
  }

  onLocationFind() {
    this.specifyLocation = false;
    if (!navigator.geolocation) {
      this.useNewLocation = false;
      return;
    }
    navigator.geolocation.getCurrentPosition((position) => {
      this.newLong = position.coords.longitude;
      this.newLat = position.coords.latitude;
      this.useNewLocation = true;
    },
    () => { // This triggers on error, e.g. user denied geolocation.
      this.useNewLocation = false;
    });
  }

  // Used to toggle map.
  onLocationSpecify() {
    this.specifyLocation = true;
  }

  onMapClick(event) {
    this.newLong = event.coords.lng;
    this.newLat = event.coords.lat;
    this.useNewLocation = true;
  }

  // Persists the updated changes to the backend.
  onUpdateSubmit() {
    if (this.useNewLocation) {
      (<any>this.user).ipinfoLoc.coordinates[0] = this.newLong;
      (<any>this.user).ipinfoLoc.coordinates[1] = this.newLat;
    }
    this.editService.editProfile(this.user, this.avatarArr,
      this.pictureArr).subscribe((obj) => {console.log(obj)});
  }
}
