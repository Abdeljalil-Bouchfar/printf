# printf

Recode C printf() with Variadic functions(Variable argument lists)

## Variable argument lists || Variadic functions

The variable argument list is a feature that allows a function to receive any number of arguments. There are situations where we want a function to handle an unknown number of arguments according to requirement.

That's how The *printf()* function is able to take any number of arguments (including zero) that can appear at that point in the function. The official term for such a declaration is a *variable argument list*.

```c
int printf(const char * restrict format, ...);
```

a variadic function adds flexibility to the program. It takes one fixed argument and then any number of arguments can be passed. The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.

In order to start creating a program that uses this structure, you must include `<stdarg.h>` in the header section of your program along with the following macros so you are actually able to access all those data points a user might have entered:

1. The type `va_list`: (ap) This one will help you initialize the arguments pointer, which will refer to each argument in turn.
2. Second, you must use `va_start`: this one initializes ap to point to the first unnamed argument, it must be called ones before ap is used. Therefore it must be at least one named argument, the last-named argument is used by `va_start`  to get started.
    
    ```c
    void va_start(va_list ap, last);
    ```
    
3. Third, each call of  `va_arg` returns one argument and step ap to point to the next argument, it takes type name as a second argument to terminate what type to return and how big a step to take in the memory.
    
    ```c
    type va_arg(va_list ap, type);
    ```
    
4. Fourth, also optional, the `va_end` macro is used to clean up the memory used by the arguments.
   ```c
   void va_end(va_list ap);
   ```


## Buffer management

From "[C Primer Plus](https://www.amazon.com/Primer-Plus-6th-Developers-Library/dp/0321928423)":

`printf()` statements sends output to an intermediate storage called the buffer. Every now and then, the material in the buffer is sent to the screen. The standard C rules for when output is sent from the buffer to the screen are clear:

1. It is sent when the buffer gets full.
2. When a newline character is encountered.
3. When there is impending input.

(Sending the output from the buffer to the screen or file is called flushing the buffer.)

---
from"[stackoverflow](https://stackoverflow.com/questions/45385807/what-is-it-with-printf-sending-output-to-buffer/1)":

Output buffering is an optimization technique. Writing data to some devices (hard disks f.e.) is an expensive operation; that's why the buffering appeared. In essence, it avoids writing data byte-by-byte (or char-by-char) and collects it in a buffer in order to write several KiB of data at once.

Being an optimization, output buffering must be transparent to the user (it is transparent even to the program). It must not affect the behavior of the program; with or without buffering (or with different sizes of the buffer), the program must behave the same. 

A buffer is just an area in memory where the data to be written is temporarily stored until enough data accumulates to make the actual writing process to the device efficient. Some devices (hard disk etc.) do not even allow writing (or reading) data in small pieces but only in blocks of some fixed size.

The rules of buffer flushing:

> It is sent when the buffer gets full.
> 

This is obvious. The buffer is full, its purpose was fulfilled, let's push the data forward to the device. Also, probably there is more data to come from the program, we need to make room for it.

> When a newline character is encountered.
> 

There are two types of devices: line-mode and block-mode. This rule applies only to the line-mode devices (the terminal, for example). It doesn't make much sense to flush the buffer on newlines when writing to disk. But it makes a lot of sense to do it when the program is writing to the terminal. In front of the terminal, there is the user waiting impatiently for output. Don't let them wait too much.

But why does output to the terminal need buffering? Writing on the terminal is not expensive. That's correct when the terminal is physically located near the processor. Not also when the terminal and the processor are half the globe apart and the user runs the program through a remote connection.

> When there is impending input.
> 

It should read "when there is impeding input on the same device" to make it clear.

Reading is also buffered for the same reason as writing: efficiency. The reading code uses its own buffer. It fills the buffer when needed then `scanf()` and the other input-reading functions get their data from the input buffer.

When an input is about to happen on the same device, the buffer must be flushed (the data actually written to the device) in order to ensure consistency. The program has sent some data to the output and now it expects to read back the same data; that's why the data must be flushed to the device in order for the reading code to find it there and load it.

### But why the buffers are flushed when the application exits?

Buffering is transparent, it must not affect the application behavior. Your application has sent some data to the output. The data must be there (on the output device) when the application quits.

The buffers are also flushed when the associated files are closed, for the same reason. And this is what happens when the application exits: the cleanup code closes all the open files (standard input and output are just files from the application point of view), closing forces flushing the buffers.
