#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @author sudeepkhadkachhetri
 * @version 1.0
 */
int main(int args, char *argv[])
{
        char *welcome = "Understanding single,double and triple pointers";
        char new[49];
        
        for (unsigned long int iter = 0; iter < strlen(welcome); iter++)
        {
          new[iter] = toupper(welcome[iter]);
        }
        welcome = new;
        // printf("%s\n\n", new);
        printf("%s\n\n", welcome);
        int x = 35;
        int *p; 
        p = &x; 
        int **q; 
        q = &p;  
        int ***r; 
        r = &q;

        printf("Address of x i.e. &x = %p\n", &x);
        printf("Address pointed by pointer p = &x = %p\n",p);
        printf("Address pointed by q i.e. q = &p[above] = : %p\n", q);
        printf("Address of pointer **q at *q = p = %p\n", *q);
        printf("Address stored at r= &q = %p\n", r);
        printf("Address stored at  pointer *r = q = %p\n\n", *r);

      
      
        printf("Value of x: %d\n", x);
        printf("Value dereference by pointer *p= %d\n", *p);
        printf("Value dereference by double pointer q: *(*q)= %d\n", *(*q));
        printf("Value dereference by triple pointer ***r = **q = *p= %d\n",  *(*(*r)));
        
        puts("");
        printf(
            "\n*****\nDISREGARD: Address of pointer p itself is: %p",
            &p);
        printf("\nDISREGARD: Address of pointer q itself is equal to "
               "the address of pointer p or , i.e. &q = %p\n*******\n",
               &q);




        return EXIT_SUCCESS;
}
