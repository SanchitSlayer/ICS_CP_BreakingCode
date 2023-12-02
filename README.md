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
```c
 if (voting==1){
        printf("Enter voterId: ");
        scanf("%d",&vid);
        if (vid>(vsize-1)){
            printf("Invalid voterId !");
            Beep(3000,1500);
            Sleep(100);
            system("cls");
        }
        else{
            arr1[vid]=vote(arr1[vid],arr,csize);
        }
        
        
    }
```
##### User is asked for his voter ID
###### E.g User enters his voter ID as 1 in the terminal (User presented with the list of candidates along with their corresponding serial number)
![](screenshots/3dec,jpg.jpg)
###### If user enters invalid voter ID, an error beep is sounded and "Invalid voter ID" message is shown.
![](screenshots/3dec.png)
###### If user chooses invalid option for his vote ,an error beep is sounded and "Invalid option" message is shown.
![](screenshots/3dec2.png)
###### After entering the choice of candidate,confirmation beep sounds,the terminal clears,vote is added to the chosen candidate and terminal is cleared to initate voting for another voter.
```c
struct voter vote(struct voter a, struct candidate arr[], int length){
    int choiced = -1;
    if (a.voted == 0){
    printf("Candidate List: \n\n");
    for (int i=0;i<length;i++){
        printf("%s (Press %d to vote %s) \n\n", arr[i].name, arr[i].candId,arr[i].name);
        
    }
    printf("Enter your choice: ");
    scanf("%d",&choiced);
    if (choiced>=length){
        printf("Invalid option");
        Beep(3000,1500);
        Sleep(100);
        system("cls");

    }
    else{
        Beep(3000,800);
        Sleep(100);
        arr[choiced].votes++;
        a.choice = choiced;
        a.voted = 1;
        //clear terminal for windows
        system("cls");
        
    }
    
    }
    else{
        printf("You have already voted once. We do not allow multiple votes !");
        Beep(3000,800);
        Sleep(100);
        Beep(3000,800);
        Sleep(100);
        system("cls");
        
    }
    return a;
}
```
##### Case 2: User types 2 into the terminal (Voting process ends sfter entering user name and password given to authorised people )
##### if user enters wrong username or password,an "Authentication failed.Invalid username or password"
![](screenshots/3dec3.png)
##### After entering correct username and password,voting process ends,final votes are calculated.Voter turnout is calculated and printed.Name of winner is printed along with the percentage of votes the winner received.
```c
int authenticate() {
    char username[20];
    char password[20];

    // Hardcoded username and password (you can replace them with your own)
    const char correctUsername[] = "breakingcode";
    const char correctPassword[] = "random";

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        return 1; // Authentication successful
    } else {
        printf("Authentication failed. Invalid username or password.\n");
        Beep(3000,1500);
            Sleep(100);
            system("cls");
        return 0; // Authentication failed
    }
}
```
```c
if (voting==2){
        if (authenticate()) {
                saveData(arr1, vsize, arr, csize);
                result(arr, csize);
                printf("\nVoter Turnout: %.2f%%\n",((float)sumVotes(arr,csize)/vsize) * 100);

                calculateWinner(arr,csize);
                refreshData(arr1,vsize,arr,csize);
                tf = 1;
                break;
            }
    }
```

