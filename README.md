# Embedded Systems and Information Processing, Institut Polytechnique de Paris Master 2 programme
This repository aims to show a little of the RAN course in C++ I followed in my master 2 programme. A RAN course is a course that has as objective to bring all master's students up to the same level in a topic necessary for the development of the programme's compulsory courses.


## TP

### How to compile and execute it?
Firstly, create a build folder inside the TP's directory. The following commands may help you:

***$ cd TP***

***$ mkdir build***

Then, go inside the created folder and type the following in order to compile to programme:
***$ cd build***

***$ cmake ..***

***$ make***

You just compiled the sensorHandler binary. In order to run it, go back to the root TP directory and execute it. Type:

***$ cd ..***

***./sensorHandler***

#### Simplified Makefile
Inside the root TP folder, you can find a Makefile which has the following make commands:

- **make** or **make all**: builds the project so you only need to create the build folder instead of doing the entire previous procedure.
- **make run**: executes the programme.
- **make clean**: clean the build folder and delete the sensorHandler binary file.

### Question 5
It was possible to achieve the following:
- Execution time when using vector: 2 seconds
- Execution time when using list: 0.5 seconds

Basically the reason for the difference between list time execution and vector time execution is the way vectors and lists work. Vectors store the data sequentially while lists do not. Each element of a list has the address of the next and the previous ones so they can "jump" into another position simulating some kind of continuity. On the other hand, vectors are always continuous so when we delete a position, some components of the vector need to be moved in order to keep sequence. And in the code, we got a lot of data retrieving, so the vector keeps being rearranged.

### Question 6
To answer that question, the OptimisedSensorBuffer class is being developed.

## Exam
