# dtgen
A minimalistic .desktop creator for GNOME and KDE

This simple program written in C takes command line arguaments and creates the contents of a .desktop file specified by the desktop entry specification (which is then can be piped, copied or whatever you want). Desktop entries are located at ~/.local/share/applications

## Currently available arguaments:
+ -a [append] append any other string at the end of the file (eg. Terminal=true)
+ -c [category] add to category, default is none (multiple categories can be separated with a semicolon)
+ -C [comment] add comment, default is none
+ -e [executable] specify executable, mandatory (check documentation for details: https://www.freedesktop.org/wiki/Specifications/desktop-entry-spec/)
+ -h display help
+ -i [icon] add icon by filename, default is none (icon from your current theme, from /usr/share/icons/hicolor/48x48/apps/ or from an absolute path)
+ -n [name] specify name, mandatory

## Installation:

Inside a terminal run:

	git clone https://https://github.com/Derisis13/dtgen

Cd to the directory you cloned into there run:

	sudo gcc main.c -o /usr/bin/dtgen

Or if you want to install it locally:

	gcc main.c -o ~/.local/bin/dtgen

Now you can use the program in the terminal. You can remove the downloaded files, and the program will stay. To uninstall it run:

	sudo rm -f /usr/bin/dtgen ~/.local/bin/dtgen

