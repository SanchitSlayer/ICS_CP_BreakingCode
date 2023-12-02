# Team information 
###  Breaking Code (Mini Voting System)
|Name|Roll no.|
|-------|-------|
|Sanchit Garg|B23CY1019|
|Vaibhav Garg|B23CM1046|
|Prashasta Srivastava|B23EE1057|
|Shlok Kanani|B23CS1068|
# How to execute the code 
This code was written in C language
###### Step 1: Download VS code
###### Step 2: If you are windows user download a gcc compiler
###### Step 3: Download the code and run it in VS code.
###### Step 4: Input the suitable data according to the instruction appearing on the terminal
# Environemt setup

# Dependencies

# Execution guidelines
#### Step1: User is presented with 2 choices
##### Case 1: User types 1 into the terminal-(Voting begins)

##### User is asked for his voter ID
###### E.g User enters his voter ID as 1 in the terminal (User presented with the list of candidates along with their corresponding serial number)
![](screenshots/3dec,jpg.jpg)
###### If user enters invalid voter ID, an error beep is sounded and "Invalid voter ID" message is shown.
![](screenshots/3dec.png)
###### If user chooses invalid option for his vote ,an error beep is sounded and "Invalid option" message is shown.
![](screenshots/3dec2.png)
###### After entering the choice of candidate,confirmation beep sounds,the terminal clears,vote is added to the chosen candidate and terminal is cleared to initate voting for another voter.

##### Case 2: User types 2 into the terminal (Voting process ends sfter entering user name and password given to authorised people )
##### if user enters wrong username or password,an "Authentication failed.Invalid username or password"
![](screenshots/3dec3.png)
##### After entering correct username and password,voting process ends,final votes are calculated.Voter turnout is calculated and printed.Name of winner is printed along with the percentage of votes the winner received.
![](screenshots/3dec4.png)
