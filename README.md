# Soccer Time

Messi used this once. He said "Es bueno, pero que es soccer?". 

https://www.youtube.com/watch?v=c1KNxuLnAYE  
 
Problem:  
​The problem my project wanted to solve was allowing a person to practice soccer alone more effectively.  
Specifically, when there is no one to pass the person the ball and no goalie to react to this system allows a simulation of that more realistic environment.  

 
Module 1:  
In order to accomplish this task there were two arduinos, one near the player and one near the goal.  
The arduino near the goal would use an ultrasonic sensor to determine a players presence and then send a signal to the motor so it can kick the ball in front of the player.  
A transistor was used to the motor to power it with a higher voltage, although this is more of a proof of concept since the digital pin is at the same 5V an the arduino power.  

 
Module 2:  
The arduino near the player would send a random signal to the second arduino when a player is detected using a 433MHz  transmitter.  
When the second arduino received the signal it then lit up the corresponding LED.  
If the left LED lit up the player would kick to that side, and same for the right LED. If they both lit up the player could do any shot they wanted.  

 
Final Analysis:  
This project worked as intended although the wireless communication was not very strong.  
Neither an antenna nor increased power via a transistor seemed to increase wireless transmission strength, a better transmitter module is likely needed.  
In the future this could be adapted to other situations, like receiving long passes if there was a more powerful motor.
