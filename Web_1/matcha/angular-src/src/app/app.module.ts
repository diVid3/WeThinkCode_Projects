// Angular Modules.
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { FlashMessagesModule } from 'angular2-flash-messages';
import { HttpClientModule } from '@angular/common/http';

// Router Module.
import { AppRoutingModule } from './app-routing.module';

// Components.
import { AppComponent } from './app.component';
import { NavbarComponent } from './components/navbar/navbar.component';
import { LoginComponent } from './components/login/login.component';
import { RegisterComponent } from './components/register/register.component';
import { HomeComponent } from './components/home/home.component';
import { ProfileComponent } from './components/profile/profile.component';

// Services.
import { AuthService } from './services/auth.service';
import { ValidateService } from './services/validate.service';
import { LocateService } from './services/locate.service';

// Guards.
import { AuthGuard } from './guards/auth.guard';
import { FooterComponent } from './components/footer/footer.component';

@NgModule({
  declarations: [
    AppComponent,
    NavbarComponent,
    LoginComponent,
    RegisterComponent,
    HomeComponent,
    ProfileComponent,
    FooterComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    FlashMessagesModule.forRoot(),
    HttpClientModule,
  ],
  providers: [
    ValidateService,
    AuthService,
    AuthGuard,
    LocateService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
