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
