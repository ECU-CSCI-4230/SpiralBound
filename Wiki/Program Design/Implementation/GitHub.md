## Repository and Branches
### Feature Procedure
Process
  - Construct a new branch using ThisTypeofCase with hyphens between significant words
    - Example, `Notebook-GUI` or `FlashCards-Import`
  - Work on your source code and commit to the branch using below guidelines
  - Make a pull request after completion

- When working on a new feature, construct an issue for significant portions of the feature
  - Assign yourself and someone else if you're working in a pair
  - Assign an appropriate milestone; labels are optional
- Use tasklists `- [ ] Text here` in markdown to break a problem down into smaller sizes
  - **NEVER** leave an issue description blank

### Committing
- Commit titles should be thoughtful and express a general idea of changes
  - Example: `Wiki: Architecture information`
  - Example: `Removed debug file; Bold/italic Markdown formatting`
  - Usually, don't commit if you've only made a 1-line change, unless it's the last change
- Commit bodies, for those commits that contain lots of features, should have lists of changes
- Commit code that is functional
  - If you are committing to seek help, comment out malfunctional code or sandbox it to a point the rest of the application runs successfully
- If a commit closes an issue, you may optionally include `Closes #x` to close it auto-magically

**Merging**:
- Merges should be kept to a minimum; work with a partner when merging
- If you clobber code reset by redownloading the branch
  - **ALWAYS** make a backup of your code before a merge if you haven't committed final changes
- Do **NOT** push directly after a merge
  - If the program malfunctions, diagnose and make an extra 'hotfix' commit before pushing
  - Validate the program runs effectively; if in doubt, have a team member verify

### General Guidelines
- Do **NOT** remove the `.gitignore` file
  - Modifications may be made only with the approval of the team
- Notify teammates that your commits influence _**immediately**_ before you make a push, unless you are otherwise aware they are not presently going to be sidetracked in progress