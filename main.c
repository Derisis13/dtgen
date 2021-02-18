#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void help(){
    printf("options:\n "
           "-a [append] append any other string at the end of the file (eg. Terminal=true)\n "
           "-c [category] add to category, default is none (multiple categories can be separated with a semicolon)\n "
           "-C [comment] add comment, default is none\n "
           "-e [executable] specify executable, mandatory, (check desktop entry documentation for details: https://www.freedesktop.org/wiki/Specifications/desktop-entry-spec/)\n "
           "-h display this help\n "
           "-i [icon] add icon by filename, default is none (icon from your current theme, from /usr/share/icons/hicolor/48x48/apps/ or from an absolute path)\n "
           "-n [name] specify name, mandatory\n");
    exit(0);
}

int argcomp(char** argv, int i, const char* const option, char** value){
    if (strcmp(argv[i], option)==0) {
        if (argv[++i]){
            *value = argv[i];
            return 1;
        }
            printf("missing option after %s\n", argv[i-1]);
            exit (12);
    }
    return 0;
};


int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("usage: \"dtgen -n name -e executable\" or \"dtgen -h\" for help\n");
        return 0;
    }
    if (strcmp(argv[1], "-h")==0)
        help();
    if (argc < 4){
        printf("usage: \"dtgen -n name -e executable\" or \"dtgen -h\" for help\n");
        return 0;
    }
    char *blank="", *comment=blank, *category=blank, *executable=NULL, *icon=blank, *name=NULL, *appendix=blank;
    for (int i = 1; i < argc; i+=2) {
        if(argcomp(argv, i, "-c", &category)) continue;
        if(argcomp(argv, i, "-C", &comment)) continue;
        if(argcomp(argv, i, "-e", &executable)) continue;
        if(argcomp(argv, i, "-i", &icon)) continue;
        if(argcomp(argv, i, "-n", &name)) continue;
        if(argcomp(argv, i, "-a", &appendix)) continue;
        printf("unexpected option: %s\n", argv[i]);
        exit(11);
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
           "Categories=%s\n"
           "%s\n" ,name ,comment ,executable, icon, category, appendix);
    return 0;
}