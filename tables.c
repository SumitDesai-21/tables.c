#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#define SIZE 1024 

typedef struct subjects {
    char sub_name[32];
    int credits;
    int sem;
} sub;

typedef struct grades {
    int marks[16];
} grades;

typedef struct marks {
    long int MIS;
    double score[16];
} marks;

char *strtoken(char *str) {
    static char *input = NULL;
    if (str != NULL) 
        input = str;
    if (input == NULL || *input == '\0') 
        return NULL;
    while (*input == ',' || *input == ' ' || *input == '\t' || *input == '\n')
        input++;
    if (*input == '\0') 
        return NULL;

    char *p = input; 

    while (*input != ',' && *input != ' ' && *input != '\t' && *input != '\n' && *input != '\0') 
        input++;

    if (*input != '\0') {
        *input = '\0';
        input++;
    }
    return p;
}
double pawr(double x, int n){
    double f = 1;
    for(int i = 0; i < n; i++)
        f *= x;
    return f;
}
double sqroot(double x){
    double y = x - 1;
    while(y * y > x)
        y = y - 1;
    y = y - 1;
    while(y * y < x)
        y = y + 0.1;
    y = y + 0.1;
    while(y * y > x)
        y = y - 0.01;
    y = y - 0.01;
    while(y * y < x)
        y = y + 0.001;
    y = y + 0.001;
    while(y * y > x)
        y = y - 0.0001;
    y = y - 0.0001;
    while(y * y < x)
        y = y + 0.00001;
    y = y + 0.00001;
    while(y * y > x)
        y = y - 0.000001;
    y = y - 0.000001;   
    while(y * y < x)
        y = y + 0.0000001;
    y = y + 0.0000001;
  
    return y;
}
void swap(marks m[], int f, int s){
    marks temp = m[f];
    m[f] = m[s];
    m[s] = temp;
}
void inssort(marks m[], int len){
    int n = len - 1;
    for (int i = n; i > 0; i--) {
        for (int j = i - 1; j < n; j++) {
            if(m[j].MIS > m[j + 1].MIS){
                swap(m,j, j+1);
            }
            else{
                break;
            }
        }
    }
}
void inssort_marks(marks m[], int len, int col){
    int n = len - 1;
    for(int i = n; i > 0; i--){
        for(int j = i - 1; j < n; j++){
            if((m[j].score)[col] < (m[j + 1].score)[col])
                swap(m, j, j + 1);
            else
                break;
        }
    }
}
int binary_search_mis(marks m[], long int target, int len){
    int l = 0;
    int h = len - 1;
    while(l <= h){
        int mid = l + (h - l)/2;
        if(m[mid].MIS == target)
            return mid;
        else if(m[mid].MIS > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int search_sub(sub s[], char *target, int len){
    for(int i = 0; i < len; i++){
        if(strcmp(s[i].sub_name, target) == 0)
            return i;
    }

    return -1;
}
void insert(char *line, sub s[], int i) {
    char *token = strtoken(line);
    strcpy(s[i].sub_name, token);

    token = strtoken(NULL);
    s[i].credits = atoi(token);

    token = strtoken(NULL);
    s[i].sem = atoi(token);
}

int readline(int fd, char *s, int size) {
    char *p = s;
    long int bytesRead;
    while ((s - p) < size - 1 && (bytesRead = read(fd, s, 1)) == 1) {
        if (*s == '\n') {
            s++;
            break;
        }
        s++;
    }

    if (bytesRead == -1) {
        perror("error");
        return -1;
    }

    if (bytesRead == 0 && (s == p)) 
        return 0;

    *s = '\0';
    return (s - p);
}

int readfile_sub(char *filename, sub s[], int size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    char buffer[SIZE];
    int i = 0;
    while (i < size && readline(fd, buffer, SIZE) > 0) {
        insert(buffer, s, i);
        i++;
    }

    close(fd);
    return i;
}

int readfile_grades(char *filename, grades g[], int size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    char buffer[SIZE];
    int i = 0;
    while (i < size && readline(fd, buffer, SIZE) > 0) {
        char *token = strtoken(buffer);
        int j = 0;
        while (token != NULL && j < size) {
            g[i].marks[j] = atoi(token);
            token = strtoken(NULL);
            j++;
        }
        i++;
    }

    close(fd);
    return i;
}
char *grade_range(double marks, grades g[], int r) {
    if(marks > (g[r].marks)[6] && marks <= 100)
        return "AA";
    else if(marks >= (g[r].marks)[5] && marks <= (g[r].marks)[6])
        return "AB";
    else if(marks >= (g[r].marks)[4] && marks <= (g[r].marks)[5])
        return "BB";
    else if(marks >= (g[r].marks)[3] && marks <= (g[r].marks)[4])
        return "BC";
    else if(marks >= (g[r].marks)[2] && marks <= (g[r].marks)[3])
        return "CC";
    else if(marks >= (g[r].marks)[1] && marks <= (g[r].marks)[2])
        return "CD";
    else if(marks > (g[r].marks)[0] && marks <= (g[r].marks)[1])
        return "DD";
    else if(marks >= 0.00 && marks <= (g[r].marks)[0])
        return "FF";
    else
        return "Invalid";
}
int readfile_marks(char *filename, marks m[], int size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }

    char buffer[SIZE];
    int i = 0;
    while (i < size && readline(fd, buffer, SIZE) > 0) {
        char *token = strtoken(buffer);
        m[i].MIS = atol(token);

        token = strtoken(NULL);
        int j = 0;
        while (token != NULL && j < size) {
            m[i].score[j] = atof(token);
            token = strtoken(NULL);
            j++;
        }
        i++;
    }

    close(fd);
    return i;
}
int get_points(char *grade){
    if(strcmp(grade, "AA") == 0)
        return 10;
    else if(strcmp(grade, "AB") == 0)
        return 9;
    else if(strcmp(grade, "BB") == 0)
        return 8;
    else if(strcmp(grade, "BC") == 0)
        return 7;
    else if(strcmp(grade, "CC") == 0)
        return 6;
    else if(strcmp(grade, "CD") == 0)
        return 5;
    else if(strcmp(grade, "DD") == 0)
        return 4;
    else if(strcmp(grade, "FF") == 0)
        return 0;
    return -1;
}
float CGPA(sub s[], grades g[], marks m[], long int mis, int r, int p){
    inssort(m, r);
    int row = binary_search_mis(m, mis, r);
    if(row == -1){
        printf("not found\n");
        exit(1);
    }
    int Numerator = 0;
    int Denominator = 0;
    for(int i = 0; i < p; i++){
        Numerator += (get_points(grade_range((m[row].score)[i], g, i)) * s[i].credits);
        Denominator += s[i].credits;
    }
    return  ((float)Numerator / Denominator);
}
float SGPA(sub s[], marks m[], grades g[],long int mis, int r, int p, int sem){
    inssort(m, r);
    int row = binary_search_mis(m, mis, r), flag = 0;
    for(int i = 0; i < p; i++){
        if(s[i].sem == sem)
            flag = 1;
    }
    if(flag == 0){
        printf("Invalid Sem\n");
        exit(1);
    }
    if(row == -1){
        printf("not found\n");
        exit(1);
    }
    int Numerator = 0, Denominator = 0;
    for(int i = 0; i < p; i++){
        if(s[i].sem == sem){
            Numerator += (get_points(grade_range((m[row].score)[i], g, i)) * s[i].credits);
            Denominator += s[i].credits;
        }
    }
    return ((float)Numerator / Denominator);
}
void failed_sub(sub s[], marks m[], grades g[],long int mis, int r, int p){
    inssort(m, r);
    int row = binary_search_mis(m, mis, r);
    if(row == -1){
        printf("not found\n");
        exit(1);
    }
    for(int i = 0; i < p; i++){
        if(get_points(grade_range((m[row].score)[i], g, i)) == 0)
            printf("%s\n", s[i].sub_name);
    }
}
void toppers_sems(sub s[], marks m[], int r, int p, int sem){
    int row = 0, col = 0, flag = 0;
    double max_marks = 0;
    for(int i = 0; i < p; i++){
        if(s[i].sem == sem)
            flag = 1;
    }
    if(flag == 0){
        printf("Invalid Sem\n");
        exit(1);
    }
    for(int i = 0; i < p; i++){
        if(s[i].sem == sem){
            col = i;
            max_marks = 0;
            for(int j = 0; j < r; j++){
                if((m[j].score)[col] > max_marks){
                    max_marks = (m[j].score)[col];
                    row  = j;
                }
            }
            printf("%ld, %s\n", m[row].MIS, s[col].sub_name);
        }
    }
}
void topper_sub(sub s[], marks m[], int p, int r, char *subject){
    int row = 0, flag = 0, col = 0;
    float max_marks = 0;
    for(int i = 0; i < p; i++){
        if(strcmp(subject, s[i].sub_name) == 0){
            flag = 1;
            col = i;
        }
    }
    if(flag == 0){
        printf("Invalid Subject\n");
        exit(1);
    }

    for(int j = 0; j < r; j++){
        if(max_marks < (m[j].score)[col]){
            max_marks = (m[j].score)[col];
            row = j;
        }
    }
    printf("%ld\n", m[row].MIS);
}
void topper_n_sub(sub s[], marks m[], int r, int q, char *subject, int n){
    int col = 0, flag = 0;
    if(n <= 0){
        printf("Invalid Value of n\n");
        exit(1);
    }
    for(int i = 0; i < q; i++){
        if(strcmp(subject, s[i].sub_name) == 0){
            col = i;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Invalid Subject\n");
        exit(1);
    }
    inssort_marks(m, r, col);
    for(int i = n - 1; i >= 0; i--)
        printf("%ld, %.2lf\n", m[i].MIS, (m[i].score)[col]);
}
void standard_dev(sub s[], marks m[], int r, int p, char *subject){
    int col = 0, N = 0;
    float sum = 0, mean = 0, Numerator = 0, std_dev = 0, flag = 0;
    for(int i = 0; i < p; i++){
        if(strcmp(s[i].sub_name, subject) == 0){
            col = i;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Invalid Sub\n");
        exit(1);
    }
    for(int i = 0; i < r; i++){
        sum += (m[i].score)[col];
        N++;
    }
    mean = sum / N;
    for(int i = 0; i < r; i++)
        Numerator += pawr(((m[i].score)[col] - mean), 2);
    std_dev = sqroot(Numerator / N);
    printf("%.2f\n", std_dev);

}
int main(int argc, char *argv[]) {
    sub s[32];
    grades g[16];
    marks m[500];

    int p = readfile_sub("./subjects.csv", s, 32);
    int q = readfile_grades("./grades.csv", g, 16);
    int r = readfile_marks("./marks.csv", m, 500);
    char input[SIZE];
    char *inputs[32];

    while (1) {
        int i = 0;
        const char *prompt = "> ";
        write(STDOUT_FILENO, prompt, strlen(prompt));

        int len = readline(STDIN_FILENO, input, SIZE);
        if (len == 0) {
            const char *eof = "EOF Occured\n";
            write(STDOUT_FILENO, eof, strlen(eof));
            break;
        }
        if (len < 0) {
            const char *error = "Invalid Input\n";
            write(STDOUT_FILENO, error, strlen(error));
            break;
        }
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        if (strcmp(input, "exit") == 0) 
            break;
        char *token = strtoken(input);
        while(token != NULL){
            inputs[i] = malloc((strlen(token) + 1) * sizeof(char));
            if(inputs[i] == NULL){
                perror("allocation failed\n");
                return 1;
            }
            strcpy(inputs[i], token);
            token = strtoken(NULL);
            i++;
        }
        if(inputs[0] == NULL){
            printf("error : give input\n");
            return 1;
        }
        if(strcmp(inputs[0], "grade") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            if(strcmp(inputs[1], "all") == 0){
                for (int i = 0; i < r; i++) {
                    printf("%ld ", m[i].MIS);
                    for (int j = 0; j < p; j++){
                        printf("%s ", grade_range((m[i].score)[j], g, j));
                    }
                    printf("\n");
                }
            }
            else if (i >= 3) {
                inssort(m, r);
                int row = binary_search_mis(m, atol(inputs[1]), r);
                if (row == -1){
                    printf("MIS-ID not found\n");
                    return 1;
                }
                int col = search_sub(s, inputs[2], p);
                if (col == -1){
                    printf("Invalid Sub\n");
                    return 1;
                }
                printf("%s\n", grade_range((m[row].score)[col], g, col));
            }
            else{
                printf("less input\n");
                break;
            }
            for (int j = 0; j < i; j++)
                free(inputs[j]);
        }
        else if(strcmp(inputs[0], "cgpa") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            printf("%.2f\n", CGPA(s, g, m, atol(inputs[1]), r, p));
        }
        else if(strcmp(inputs[0], "sgpa") == 0){
            if(inputs[1] == NULL || inputs[2] == NULL){
                printf("less input\n");
                return 1;
            }
            printf("%.2f\n", SGPA(s, m, g, atol(inputs[1]), r, p, atoi(inputs[2])));
        }
        else if(strcmp(inputs[0], "failed") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            failed_sub(s, m, g, atol(inputs[1]), r, p);
        }
        else if(strcmp(inputs[0], "topsem") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            toppers_sems(s, m, r, p, atoi(inputs[1]));
        }
        else if(strcmp(inputs[0], "topsub") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            topper_sub(s, m, p, r, inputs[1]);
        }
        else if(strcmp(inputs[0], "topnsub") == 0){ 
            if(inputs[1] == NULL || inputs[2] == NULL){
                printf("less input\n");
                return 1;
            }
            topper_n_sub(s, m, r, q, inputs[1], atoi(inputs[2]));
        }
        else if(strcmp(inputs[0], "stdev") == 0){
            if(inputs[1] == NULL){
                printf("less input\n");
                return 1;
            }
            standard_dev(s, m, r, p, inputs[1]);
        }
        else{
            printf("Invalid Input\n");
            return 1;
        }
    }
    return 0;
}

