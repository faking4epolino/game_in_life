###Rules###
1) The input DRP is read from the file passed as
  a command line argument. The file is a set of numbers 0 and 1, separated by spaces and
  line breaks. The correctness of the file contents is guaranteed.
2) The second command-line argument specifies the name of the output file,
  in which after each step it is necessary to write:
  a. information about the number of cells born at this step;
  b. the state of the matrix in symbolic form.
  This information should be presented in HTML format.
3) The input is looped, keystrokes are read; while any key is pressed except
  Escape – do one iteration if the Escape key is pressed.
