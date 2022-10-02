#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAXIMUM_PARTICIPANTS = 5;
const int MAXIMUM_PARTICIPANT_NAME_LENGTH = 50;


int getNumberOfParticipants() {
    int numberOfParticipants;
    do {
        printf("Please enter the number of participants in this journey (max. %d): ", MAXIMUM_PARTICIPANTS);
        scanf("%d", &numberOfParticipants);

        if (numberOfParticipants <= 1) {
            printf("This number of participants is not valid. (Too low.)\n");
            continue;
        }
        if (numberOfParticipants > MAXIMUM_PARTICIPANTS) {
            printf("This number of participants is not valid. (Too high.)\n");
            continue;
        }
        break;
    } while( true );

    return numberOfParticipants;
}

void requestParticipantNames(int numberOfParticipants, char (*participantsNames)[MAXIMUM_PARTICIPANT_NAME_LENGTH]) {
    for (int i = 0; i < numberOfParticipants; i++) {
      char participant[MAXIMUM_PARTICIPANT_NAME_LENGTH];

      char scanfInputMask[10];
      snprintf(scanfInputMask, 10, "%%%ds", MAXIMUM_PARTICIPANT_NAME_LENGTH-1);

      printf("Please enter Participant number %d name: ", i + 1);
      scanf(scanfInputMask,participant);
      strcpy(participantsNames[i], participant);
    }
}


int main(void) {
    printf("\t Splitty, Your Journey Friend!\t\n");

    char participantsNames[MAXIMUM_PARTICIPANTS][MAXIMUM_PARTICIPANT_NAME_LENGTH];
    int numberOfParticipants = getNumberOfParticipants();
    requestParticipantNames(numberOfParticipants, participantsNames);
    
    for (int i = 0; i < numberOfParticipants; i++) {
        printf("%s\n", participantsNames[i]);
    }
}
