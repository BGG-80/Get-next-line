# Get-next-line
Get Next Line Leer una línea de un file descriptor es demasiado aburrido Resumen: El objetivo de este proyecto es simple: programar una función que devuelva una línea leída de un file descriptor. 

After this project , you will see increased the following skills : 
  - Rigor
  - Unix
  - Algorithms & AI 

Essential Knowledge for a Good get_next_line Implementation

To successfully implement get_next_line, you need a solid understanding of the following concepts:

🔹 File Descriptors (FDs):

    What they are and how they work in UNIX systems.
    How to use them with open(), read(), and close().

🔹 Memory Management in C:

    Dynamic allocation with malloc() and free().
    Avoiding memory leaks and handling buffer allocation properly.

🔹 Buffers and Reading Mechanisms:

    Using a buffer to store data from read().
    Understanding how read() works and how it returns data in chunks.

🔹 String Manipulation Functions:

    Implementing or using ft_strchr(), ft_strdup(), ft_strjoin(), or ft_substr() can be really useful to manage strings dynamically.

🔹 Handling Static Variables:

    How to store leftover data between function calls using static variables.

🔹 Edge Cases and Errors:

    Handling end-of-file (EOF) correctly.
    Managing invalid file descriptors or read errors.
    Ensuring the function returns NULL when appropriate.

🔹 Bonus (Multiple File Descriptors):

    Using linked lists or an array to handle multiple file descriptors simultaneously.

Mastering these concepts will help you write an efficient, memory-safe, and norm-compliant get_next_line function. 🚀
