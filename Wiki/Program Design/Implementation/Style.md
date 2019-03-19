## Programming Standards
Qt Creator auto-magically performs stylistic and error checks on source as it's written; however, the following style is preferred when writing new source code:
- 4-spaced tab indentations, as shown below
  ```C++
  void main() {
      for(int i=0; i<5; i++) {
          cout << "Some text" << endl;
      }
      return 0;
  }
  ```
- Placing of `{` on the same line as a function definition, or directly after, with `}` on its own line after the definition's closure; the only exception is in the case of single-line functions, such as `bool isTrue() { return true; }`
- Insertion of the following documentation above functions/methods:
  ```C++
  // Author:      name
  // Init Date:   mm-dd-yyyy
  // Last Updated: mm-dd-yyyy
  ```
- Documentation using `/**/` and `//` for complex code, such as complicated for loops or otherwise-obscure lines (for example, disabling sorting before inserting data into a table, such as to avoid asynchronous sorting during insert)
- Documentation using `/**/` for function contracts, usually in classes that provide helper functions

Warnings that are allowed, generally, are:
- Old-typecast warnings (such as using `(int) longVal`)

## Code Review
- Test your programs incrementally; use debug statements using `qDebug()`
  - If you implement a for loop that does something on the interface, test it
  - If you make a small popup ui and use it to change the main window, use debug statements
- If you're struggling, seek a teammate's assistance with troubleshooting code
  - Provide a description of **where** and **what** the problem is
  - Demo what happens to produce the problem
  - Offer insightful speculation as to **why** the problem may occur
  - **ALWAYS** provide information about what and where you found information to fix the problem
- Push code to local branches - never directly to master (unless approved by the team)
  - If you break your code, this makes it easier to rollback using `git reset HEAD^ --soft