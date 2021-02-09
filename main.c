#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void help(){
    printf("options:\n "
           "-C [category] add to category, default is none (multiple categories can be separated with a semicolon)\n "
           "-c [comment] add comment, default is none\n "
           "-e [executable] specify executable, mandatory, (check desktop entry documentation for details: https://www.freedesktop.org/wiki/Specifications/desktop-entry-spec/)\n "
           "-h display this help\n"
           "-i [icon] add icon by filename, default is none (icon from your current theme, from /usr/share/icons/hicolor/48x48/apps/ or from an absolute path)\n "
           "-n [name] specify name, mandatory\n");
    exit(0);
}


int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("usage: \"dtgen -n name -e executable\" or \"dtgen -h\" for help\n");
        return 0;
    }
    if (strcmp(argv[1], "-h")==0)
        help();
    if (argc < 2){
        printf("usage: \"dtgen -n name -e executable\" or \"dtgen -h\" for help\n");
        return 0;
    }
    char *blank="", *comment=blank, *category=blank, *executable=NULL, *icon=blank, *name=NULL;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-c")==0) {
            comment = argv[++i];
            continue;
        }
        if (strcmp(argv[i], "-C")==0) {
            category = argv[++i];
            continue;
        }
        if (strcmp(argv[i], "-e")==0) {
            executable = argv[++i];
            continue;
        }
        if (strcmp(argv[i], "-i")==0) {
            icon = argv[++i];
            continue;
        }
        if (strcmp(argv[i], "-n")==0) {
            name = argv[++i];
            continue;
        }
        else {
            printf("unexpected option: %s\n", argv[i]);
            exit(11);
        }
    }
    if (!executable && !name){
        printf("missing name or executable\n");
        exit(20);
    }
    printf("[Desktop Entry]\n"
           "Type=Application\n"
           "Name=%s\n"
           "Comment=%s\n"
           "Exec=%s\n"
           "Icon=%s\n"
           "Categories=%s\n" ,name ,comment ,executable, icon, category);
    return 0;
}
