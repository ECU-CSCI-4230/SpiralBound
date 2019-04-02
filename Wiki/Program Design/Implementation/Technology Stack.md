## Stack and Software
### Development Stack
- Development Kit
  - **Qt Creator 4.8.2, using Qt 5.12.0**
    - _C++-based GUI creator in which the software is primarily developed_
    - https://www.qt.io/download
    - Installer Options
      - Qt > Qt 5.12.0
        - MSVC 2015 64-bit
        - MSVC 2017 32-bit
        - MSVC 2017 64-bit
        - Qt WebEngine
        - Qt Debug Information Files
      - Qt > Developer and Designer Tools
        - Qt Creator 4.8.2 CDB Debugger Support
  - **Windows 10 Software Development Kit**
    - _Windows SDK for loading in the MSVC compiler_
    - https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk
    - Installer Options
      - Debugging Tools for Windows
      - Application Verifier for Windows
      - Windows App Certification Kit
      - MSI Tools
      - Windows SDK Signing Tools for Desktop Apps
      - Windows SDK for ... _[all options prefixed by this: UWP, C++, etc]_
- Git CLI, GitHub Desktop
  - _Commit and branch management (aside from Qt's built-in manager)_
- Visual Studio Code
  - _Lightweight IDE that has git management tools and can edit Markdown and other source files_

### Other Software
- Discord
  - _Communication medium for the team_

## Onboarding
The following procedure should be followed regarding MacOS and Windows 10. You should have a preferred minimum of 4 GB of RAM and a quad-core processor at 2.0 GHz for optimal development. (For best development, use a screen with 1920x1080 screen resolution).

1. Download and install Git CLI (or Git Desktop). Configure username and e-mail using `git config --global user.name <name>` and `git config --global user.email <email>`.
2. Download and install Visual Studio Code and Qt Creator 4.8.2. Use the open-source version of Qt and select only the options above for minimal installation size.
3. Download and install the Windows 10 Software Development Kit from the above reference, selecting all above-listed options.
4. Configuration of Qt Creator with Windows 10 SDK:
    - In Qt Creator, click `Tools > Options...`
    - Under the 'Compilers' tab, validate that MSVC compilers are detected; there should be four with the following in parentheticals: x86, amd64_x86, amd64, x86_amd64. There should be these options under both 'C' and 'C++' under 'Auto-detected'.
    - Under the 'Debuggers' tab, you will need to add 2 manual compilers - refer to them as 'Win 10 SDK Debugger x86' and 'Win 10 SDK Debugger x64.' They should be found at these locations:
      - `C:\Program Files (x86)\Windows Kits\10\Debuggers\x86\cdb.exe` for x86
      - `C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe` for x64
    - Under the 'Kits' tab, perform the following for MSVC2017 32bit/64bit in the 'Auto-detected' section. We will use x86 as example:
        1. Select the kit `MSVC2017 32bit`
        2. Under 'Compiler > C++', select `Microsoft Visual C++ Compiler 15.0 (x86)`
        3. Under 'Debugger', select `Win 10 SDK Debugger x86`
5. Clone the repository using git `git clone <url> -b <branch>`, or download the master branch and use Qt Creator to change branches.

### Onboarding Screenshots
![Win-10-SDK](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Implementation/images/Windows%20SDK.png)
<br />
_Figure 1:_ Installer options for the Windows 10 SDK

![Creator-Compiler-Autodetect](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Implementation/images/Creator-Compiler.png)
<br />
_Figure 2:_ Autodetection of the MSVC compilers as seen in Qt Creator's `Tools > Options...` menu

![Creator-Debugger-Options](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Implementation/images/Creator-Debugger.png)
<br />
_Figure 3:_ Showcase of the creation of the manual compilers for MSVC, showcasing the sample filepath described.

![Creator-Kits-Tab](https://raw.githubusercontent.com/ECU-CSCI-4230/SpiralBound/master/Wiki/Program%20Design/Implementation/images/Creator-Kits.png)
<br />
_Figure 4:_ Showcase of the configuration of the MSVC compiler, with the C++ and Debugger selected (highlighted as yellow in the screenshot). 

_You'll need to contact someone on the team about getting you into the Discord server, where most communication about the project arises. You should also seek assistance if you encounter issues with onboarding._