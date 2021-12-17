/** keep in mind my weak point is perfect syntax so my syntax may need to be fine tuned */

/** prototype */

typedef struct buffer_t

{

	int line_number;
	int len;
	char buffer[1024];
	int i;
} buffer_t;

---------------------------

/** use */

buff_t new_buff;

if (@ptr1 < BOOL=FALSE)
{
  printf(stderr, "USEAGE: monty <file>\n");
  exit(EXIT_FAILURE);
}

----------------


/** reading lines */

while ((read = getline(&line, *len,)) < 0)  
{
  printf("%s", new_buffer.buffer);
  printf("%d\n," new_buffer.line_number);
  printf(new_buffer.buffer, "%s", line);
  length = (buffer.length-1);   /** declare the length of the buffer the current size */
new_buffer.line_number = (buffer.length-1 + 1));  /** will take buffer length and increase by 1 for new line */


-------------------------

/** Executing */

something like


#include <stdio.h>

int main()
char *line = NULL;
size_t len= 0;

while (1==1)
{
  printf("enter command");
  scanf()
  getline(&line, &len, stdin);
  char* args[] = {"/bin/ls", NULL};   /** lets hypothetically say user executes ls so ls is the input from method stdin states, in this case the line from scanf(), and gives room for arguments */
  execve("/bin/ls", args, eng); /** executes the binary for ls */
}
