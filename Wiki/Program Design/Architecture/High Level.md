## High-Level Architecture
The high-level architecture of our system is primarily based on the Model-View-Controller architecture. The model of the application is the notebook data structure, calendar event list, and the flash cards list. The control of the program is mixed in with the views of the application - that is, the interface of the system, as it both allows the user to view the data contained within and make modifications and changes using buttons and a menubar.

## Diagram
![Architecture Diagram](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Architecture/diagram/Architecture%20Diagram.png)

In the above diagram, you can see that there is a central model box, with three `-Model-` blocks pointing to it. These three boxes represent the different, major data structures (or implied structures of data) for the application. You can then see that there are three major `VC` boxes - these represent the view/control windows. These three boxes are then pointed to by smaller prompts, such as for adding cards or deleting calendar events.