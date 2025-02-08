        // Query Processing For Faculty
        if(QueryType == 1) {
            printf("\nEnter Query ID: ");
            scanf("%s", &Faculty[FacultyCount].QueryID[0]);
            FTime:
            printf("Enter Query Arrival Time: ");
            scanf("%d", &AT);
            // Check Time constraint
            if(AT<1000 || AT>1200 || (AT<1100 && AT>1059) || (AT<1200 && AT>1159)) {
                printf("\nEnter Correct Time!\n");
                goto FTime;
            }
            else {  // Simplifying ArrivalTime for further calculations
                if (AT>=1000 && AT<1100) {
                    Faculty[FacultyCount].ArrivalTime = AT-1000;
                }
                else {
                    Faculty[FacultyCount].ArrivalTime = AT-1040;
                }
            }
            FBTime:
            printf("Enter Burst Time: ");
            scanf("%d", &BT);
            if(Burst - BT < 0 || BT <= 0 || Faculty[FacultyCount].ArrivalTime + BT >= 120) {    // initially Burst=120 
                if(BT<=0) {
                printf("\nBurst Time cannot be less than 0\n"); }
                else {
                    if (Burst-BT<=0) {
                        int choice;
                        printf("\nSudesh Sharma will not have enough time to handle this Query because of high BurstTime."
                        "\nWant to change BurstTime? (1 : Yes; Else : No) ");
                        scanf("%d", &choice);
                        if(choice==1) { goto FBTime; }
                        else {
                            printf("\nOK. This query's all data will be lost\n");
                            goto TryQuery;
                        }
                    }
                    else {
                        printf("\nInvalid Burst time for corresponding Arrival Time\n");
                    }
                }
                printf("Please enter valid Burst Time\n");
                goto FBTime;
            }
            else {
                Faculty[FacultyCount].BurstTime = BT;
            }
            Burst -= BT;    // Updates Total Remaining Burst time
            Faculty[FacultyCount].TotalTime = Faculty[FacultyCount].BurstTime;
            FacultyCount++;
        }

        // Query Processing For Student
        else if(QueryType == 2) {
            printf("\nEnter Query ID: ");
            scanf("%s", &Student[StudentCount].QueryID[0]);
            STime:
            printf("Enter Query Arrival Time: ");
            scanf("%d", &AT);
            // Check Time constraint
            if(AT<1000 || AT>1200 || (AT<1100 && AT>1060) || (AT<1200 && AT>1160)) {
                printf("\nEnter valid Time!\n");
                goto STime;
            }
            else {
                if (AT>=1000 && AT<1100) {
                    Student[StudentCount].ArrivalTime = AT-1000;
                }
                else {
                    Student[StudentCount].ArrivalTime = AT-1040;
                }
            }
            SBTime:
            printf("Enter Burst Time: ");
            scanf("%d", &BT);
            if(Burst - BT < 0 || BT <= 0 || Student[StudentCount].ArrivalTime + BT >= 120) {    // initially Burst=120
                if(BT<=0) {
                printf("\nBurst Time cannot be less than 0\n"); }
                else {
                    if (Burst-BT<=0) {
                        int choice;
                        printf("\nSudesh Sharma won't have enough time to handle this Query because of high BurstTime."
                        "\nWant to change BurstTime? (1 : Yes; Else : No) ");
                        scanf("%d", &choice);
                        if(choice==1) {
                            goto FBTime;
                        }
                        else {
                            printf("\nOK. This query's all data will be lost\n");
                            goto TryQuery;
                        }
                    }
                    else {
                        printf("\nInvalid Burst time for corresponding Arrival Time\n");
                    }
                }
                printf("Please enter valid Burst Time\n");
                goto SBTime;
            }
            else {
                Student[StudentCount].BurstTime = BT;   // Updates Total Remaining Burst time
            }
            Burst -= BT;
            Student[StudentCount].TotalTime = Student[StudentCount].BurstTime;
            StudentCount++;
        }
        else {  // In case any other wrong input
            printf("\nInvalid Input. Please try again.\n");
            goto TryQuery;
        }
    }
}
