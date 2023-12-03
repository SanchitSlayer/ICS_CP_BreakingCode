// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

struct candidate{
    int votes;
    char name[100];
    int candId;
    
};

struct voter{
    
    char name[100];
    int voterId;
    int choice;
    int voted ;
    
};

int sumVotes(struct candidate arr[], int csize) {
    int totalVotes = 0;

    for (int i = 0; i < csize; i++) {
        totalVotes += arr[i].votes;
    }

    return totalVotes;
}

void calculateWinner(struct candidate arr[], int csize) {
    int maxVotes = arr[0].votes;
    int winnerIndex = 0;
    int winnerCount = 1;

    // Find the candidate with the maximum votes
    for (int i = 1; i < csize-1; i++) {
        if (arr[i].votes > maxVotes) {
            maxVotes = arr[i].votes;
            winnerIndex = i;
        }
    }

    for (int i=0;i<csize-1;i++){
        if ((arr[i].votes==maxVotes)&&(winnerIndex!=i)){
            winnerCount ++;
        }
    }

    if (winnerCount==1){
        printf("\nWinner: %s\n", arr[winnerIndex].name);
        // printf("Votes received: %d\n", arr[winnerIndex].votes);
        printf("Percentage of votes of winner: %.2f%%\n", (float)arr[winnerIndex].votes / (float)sumVotes(arr, csize) * 100);

    }
    else{
        printf("Tie between the following candidates: ");
        for (int i=0;i<csize-1;i++){
            if (arr[i].votes==maxVotes){
                printf("%s ",arr[i].name);
            }

        }
    }

    
}


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



// Function to save voters and candidates to a file
void saveData(struct voter arr1[], int vsize, struct candidate arr[], int csize) {
    FILE *file = fopen("voting_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save voters
    fprintf(file, "Voters:\n");
    // fprintf(file,"// Voter VoterId Choice Voting_status ");
    for (int i = 0; i < vsize; i++) {
        fprintf(file, "%s %d %d %d\n", arr1[i].name, arr1[i].voterId, arr1[i].choice, arr1[i].voted);
    }
    // Save candidates
    fprintf(file, "\nCandidates:\n");
    for (int i = 0; i < csize; i++) {
        fprintf(file, "%s %d %d\n", arr[i].name, arr[i].candId, arr[i].votes);
    }

    fclose(file);
}

void refreshData(struct voter arr1[], int vsize, struct candidate arr[], int csize){
    FILE *file = fopen("voting_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save voters
    fprintf(file, "Voters:\n");
    // fprintf(file,"// Voter VoterId Choice Voting_status ");
    for (int i = 0; i < vsize; i++) {
        fprintf(file, "%s %d %d %d\n", arr1[i].name, arr1[i].voterId, -1,0);
    }
    // Save candidates
    fprintf(file, "\nCandidates:\n");
    for (int i = 0; i < csize; i++) {
        fprintf(file, "%s %d %d\n", arr[i].name, arr[i].candId, 0);
    }

    fclose(file);

}


void loadData(struct voter arr1[], int *vsize, struct candidate arr[], int *csize) {
    FILE *file = fopen("voting_data.txt", "r");

    if (file == NULL) {
        printf("No previous data found.\n");
        return;
    }

    // Load voters
    fscanf(file, "Voters:\n");
    while (fscanf(file, "%s %d %d %d", arr1[*vsize].name, &arr1[*vsize].voterId, &arr1[*vsize].choice, &arr1[*vsize].voted) == 4) {
        (*vsize)++;
    }

    // Load candidates
    fscanf(file, "Candidates:\n");
    while (fscanf(file, "%s %d %d", arr[*csize].name, &arr[*csize].candId, &arr[*csize].votes) == 3) {
        (*csize)++;
    }

    fclose(file);
}


struct voter vote(struct voter a, struct candidate arr[], int length){
    int choiced = -1;
    if (a.voted == 0){
    printf("Candidate List: \n\n");
    for (int i=0;i<length;i++){
        printf("%s (Press %d to vote %s) \n\n", arr[i].name, arr[i].candId,arr[i].name);
        
    }
    printf("Enter your choice (Please enter only integral values): ");
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

void newVoter(struct voter arr[], int size){
    struct voter stud;
    printf("Enter name;");
    char tempc[100];
    scanf("%s",tempc);
    strcpy(stud.name,tempc);
    stud.voterId = size;
    stud.choice = -1;
    printf("Your voter Id is %d", size);
    stud.voted = 0;
    arr[size] = stud;
    
}

void newCand(struct candidate arr[], int size){
    struct candidate a;
    printf("Enter name: ");
    char tempc[100];
    scanf("%s", tempc);
    strcpy(a.name,tempc);
    a.candId = size;
    a.votes=0;
    // append this to voter array.
    arr[size] = a;
    
}


void result(struct candidate arr[],int size){
    printf("The results are as follows\n");
    for (int i=0;i<size;i++){
        printf("%d. %s: %d votes\n",i+1,arr[i].name,arr[i].votes);
    }
}

int main() {
    
    int voting;
    struct candidate* arr = (struct candidate*)malloc(1000 * sizeof(struct candidate));
    struct voter* arr1 = (struct voter*)malloc(1000 * sizeof(struct voter));
    int csize = 0;
    int vsize = 0;

    loadData(arr1, &vsize, arr, &csize);

    int vid;
    int tf;
    tf=0;
    while (tf==0){
    
    printf("\n1. Vote");
    // printf("\n2. New Voter");
    // printf("\n3. New Candidate");
    printf("\n2. Finish process");
    printf("\nEnter choice (Please enter integral values): ");
    // scanf("%d",&voting);

    if (scanf("%d", &voting) != 1 || voting<=0 || voting >=3) {
                printf("Invalid choice. Please enter a valid integer.\n");
                Beep(3000, 1500);
                Sleep(100);
                while (getchar() != '\n');  // Clear the input buffer
                system("cls");
                continue;
            }
    else{

    
    if (voting==1){
        printf("Enter voterId (Please enter only integral values) : ");
        if (scanf("%d", &vid) != 1) {
        printf("Invalid voterId. Please enter a valid integer.\n");
        Beep(3000, 1500);
        Sleep(100);
        while (getchar() != '\n');  // Clear the input buffer
        system("cls");
        continue;
    }

    // Check if vid is within a valid range
    if (vid < 0 || vid >= vsize) {
        printf("Invalid voterId!\n");
        Beep(3000, 1500);
        Sleep(100);
        system("cls");
        continue;
    }

    // Proceed to vote function only if vid is a valid integer
    arr1[vid] = vote(arr1[vid], arr, csize);
        
    }
 
    if (voting==2){
        if (authenticate()) {
                saveData(arr1, vsize, arr, csize);
                result(arr, csize);
                printf("\nVoter Turnout: %.2f%%\n",((float)sumVotes(arr,csize)/vsize) * 100);

                calculateWinner(arr,csize);
                // refreshData(arr1,vsize,arr,csize);
                tf = 1;
                break;
            }
    }
    
    if (csize >= 1000) {
            // Resize arr using realloc
            arr = (struct candidate*)realloc(arr, 2 * csize * sizeof(struct candidate));
            if (arr == NULL) {
                printf("Memory reallocation failed.\n");
                return 1; // Exit the program with an error code
            }
        }

        if (vsize >= 1000) {
            // Resize arr1 using realloc
            arr1 = (struct voter*)realloc(arr1, 2 * vsize * sizeof(struct voter));
            if (arr1 == NULL) {
                printf("Memory reallocation failed.\n");
                return 1; // Exit the program with an error code
            }
        }
    }

    }

    return 0;
}
