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
  btnSecondary0: boolean = false;
  btnSecondary1: boolean = false;
  btnSecondary2: boolean = false;
  btnSecondary3: boolean = false;
  btnSecondary4: boolean = false;
  btnSecondary5: boolean = false;
  btnSecondary6: boolean = false;
  btnSecondary7: boolean = false;
  btnSecondary8: boolean = false;
  btnSecondary9: boolean = false;
  btnOutlineSecondary0: boolean = true;
  btnOutlineSecondary1: boolean = true;
  btnOutlineSecondary2: boolean = true;
  btnOutlineSecondary3: boolean = true;
  btnOutlineSecondary4: boolean = true;
  btnOutlineSecondary5: boolean = true;
  btnOutlineSecondary6: boolean = true;
  btnOutlineSecondary7: boolean = true;
  btnOutlineSecondary8: boolean = true;
  btnOutlineSecondary9: boolean = true;

  constructor(private authService: AuthService) { }

  ngOnInit() {
    this.authService.getProfile().subscribe(profile => {
      this.user = (<any>profile).user;
      this.long = (<any>this.user).ipinfoLoc.coordinates[0];
      this.lat = (<any>this.user).ipinfoLoc.coordinates[1];

      // Detecting Interest States
      this.btnSecondary0 = (<any>this.user).interests.includes('Matcha');
      this.btnSecondary1 = (<any>this.user).interests.includes('Sports');
      this.btnSecondary2 = (<any>this.user).interests.includes('Art');
      this.btnSecondary3 = (<any>this.user).interests.includes('Gaming');
      this.btnSecondary4 = (<any>this.user).interests.includes('Traveling');
      this.btnSecondary5 = (<any>this.user).interests.includes('Music');
      this.btnSecondary6 = (<any>this.user).interests.includes('Cooking');
      this.btnSecondary7 = (<any>this.user).interests.includes('Reading');
      this.btnSecondary8 = (<any>this.user).interests.includes('Computers');
      this.btnSecondary9 = (<any>this.user).interests.includes('Movies');

      this.btnOutlineSecondary0 = !this.btnSecondary0;
      this.btnOutlineSecondary1 = !this.btnSecondary1;
      this.btnOutlineSecondary2 = !this.btnSecondary2;
      this.btnOutlineSecondary3 = !this.btnSecondary3;
      this.btnOutlineSecondary4 = !this.btnSecondary4;
      this.btnOutlineSecondary5 = !this.btnSecondary5;
      this.btnOutlineSecondary6 = !this.btnSecondary6;
      this.btnOutlineSecondary7 = !this.btnSecondary7;
      this.btnOutlineSecondary8 = !this.btnSecondary8;
      this.btnOutlineSecondary9 = !this.btnSecondary9;
    },
    err => {
      console.log(err);
      return false;
    });
  }

  // Takes an interest string, e.g 'Matcha'.
  removeInterest(interest) {
    let stringIndex = (<any>this.user).interests.indexOf(interest);
    (<any>this.user).interests.splice(stringIndex, 1);
    this.btnSecondary0 = false;
    this.btnOutlineSecondary0 = true;
  }

  // Takes an interest string, e.g 'Matcha'.
  addInterest(interest) {
    (<any>this.user).interests.push(interest);
    this.btnSecondary0 = true;
    this.btnOutlineSecondary0 = false;
  }

  // toggleInterest(event) {
  //   console.log(event);
  //   let interest = event.srcElement.innerHTML;
  //   if ((<any>this.user).interests.includes(interest))
  //     this.removeInterest(interest);
  //   else
  //     this.addInterest(interest);
  // }
  toggleInterest(event) {
    console.log(event);
    let interestString = event.srcElement.innerHTML;
    switch (interestString) {
      case "Matcha":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Sports":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Art":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Gaming":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Traveling":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Music":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Cooking":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Reading":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Computers":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
      case "Movies":
        if ((<any>this.user).interests.includes(interestString)) {
          this.removeInterest(interestString)
        } else {
          this.addInterest(interestString)
        }
    }
  }
}
