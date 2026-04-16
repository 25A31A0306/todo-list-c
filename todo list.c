#include <stdio.h>
#include <string.h>

#define MAX 100

char tasks[MAX][100];
int done[MAX] = {0};
int count = 0;

// Add Task
void addTask() {
    if (count >= MAX) {
        printf("Task list full!\n");
        return;
    }

    printf("Enter task: ");
    getchar(); // clear buffer
    fgets(tasks[count], 100, stdin);

    // remove newline
    tasks[count][strcspn(tasks[count], "\n")] = 0;

    done[count] = 0;
    count++;

    printf("Task added successfully!\n");
}

// View Tasks
void viewTasks() {
    if (count == 0) {
        printf("No tasks available!\n");
        return;
    }

    printf("\n===== YOUR TASKS =====\n");

    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n", i + 1, done[i] ? "✔" : " ", tasks[i]);
    }
}

// Delete Task
void deleteTask() {
    int num;

    if (count == 0) {
        printf("No tasks to delete!\n");
        return;
    }

    viewTasks();

    printf("Enter task number to delete: ");
    scanf("%d", &num);

    if (num < 1 || num > count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = num - 1; i < count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
        done[i] = done[i + 1];
    }

    count--;

    printf("Task deleted successfully!\n");
}

// Mark Task as Done
void markDone() {
    int num;

    if (count == 0) {
        printf("No tasks available!\n");
        return;
    }

    viewTasks();

    printf("Enter task number to mark as done: ");
    scanf("%d", &num);

    if (num < 1 || num > count) {
        printf("Invalid task number!\n");
        return;
    }

    done[num - 1] = 1;

    printf("Task marked as done!\n");
}

// Main
int main() {
    int choice;

    while (1) {
        printf("\n=============================\n");
        printf("        TO-DO LIST APP\n");
        printf("=============================\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task as Done\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: markDone(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}