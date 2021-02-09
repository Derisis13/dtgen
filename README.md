# dtgen
A minimalistic .desktop creator for GNOME

This simple program takes command line arguaments and creates the contents of a .desktop file specified by the desktop entry specification (which is then can be piped, copied or whatever you want).

## Currently available arguaments:
+ -C [category] add to category, default is none (multiple categories can be separated with a semicolon)
+ -c [comment] add comment, default is none
+ -e [executable] specify executable, mandatory (check documentation for details: https://www.freedesktop.org/wiki/Specifications/desktop-entry-spec/)
+ -h display this help
+ -i [icon] add icon by filename, default is none (icon from your current theme, from /usr/share/icons/hicolor/48x48/apps/ or from an absolute path)
+ -n [name] specify name, mandatory
