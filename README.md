# Introducing: The KnöchBox, or an Exercise in the Unecessarily Bavarian-themed Naming of a Puzzle Box

![alt text][intro]

[intro]: https://github.com/tantantheman/tantan-knochbox/blob/master/photos/knochoverview.jpeg "Knochbox Overview"

A puzzle box for class. Module 4/5, Task 2 (Kinetic Art).  
Programming in Arduino IDE.  

**Dependencies:**  
ESP32Servo.h  
Stepper.h

**How to play:**  

Objective: The goal in the box is to try and guess the correct sequence of knocks in order to "unlock" the puzzle box. If the number of knocks in a set is correct, you advance onto the next section of the 5-set sequence. An incorrect guess will reveal how close you were to guessing that set, allowing you to try again. If you go over the number of knocks in a set, the accuracy displays as 0%. When the box is unlocked, it resets. 

**How to run:**  
Plug in ESP32 inside the KnöchBox by opening up the top lid, and extending cable out through side panel with cutout. Enjoy!
  
**Implementation:**  
To create the puzzle box that is the KnöchBox, only a few parts were actually needed.

The enclosure was largely inspired by that of the Fart-O-Matic, where utilizing the top panel of the box essentially as a large button allows for the "knocking" effect that the user can use to interact with the box.

![alt text][panel]

[panel]: https://github.com/tantantheman/tantan-knochbox/blob/master/photos/knochpanel.jpeg "Knochbox Guages"

Mechanics wise, there are three servo motors that act as guages, one that tells the "closeness" or accuracy of the knock attempt, one that tells the player how close they are to unlocking the box, and finally one guage that indicates the locked/unlocked status of the box.  

![alt text][inside]

[inside]: https://github.com/tantantheman/tantan-knochbox/blob/master/photos/knochinside.jpeg "Knochbox Inside"

![alt text][servo]

[servo]: https://github.com/tantantheman/tantan-knochbox/blob/master/photos/knochservo.jpeg "Knochbox Servos"

There is also a button that is implemented in the same way as the Fart-O-Matic, allowing for the previously discussed top knocking panel.  

**Technical Difficulties:**  
The largest technical difficulty with building this project was actually figuring out a way to attach the motors in a way that worked with the thickness of the wooden enclosure. At the end, a combination of electric tape and shipping tape seemed to do the trick. In addition, calibrating the knocking to register successfully, and figuring out a timing to register an attempt was difficult, as it just relied on trial and error. 

**Video**  
A video of the KnöchBox in action can be found here:  
https://youtu.be/6DZXhUA5q48  
