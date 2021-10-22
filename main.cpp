#define _XOPEN_SOURCE_EXTENDED 1
#include<ncurses.h>
#include<clocale>
#include<cstring>

#define COUNT 5
#define PINK 1

using namespace std;

void center(int row, char *title);

int main() {
    char text[] = "Armstrong walks on moon!";
    char *t;
    char a;
    int len;

    initscr();
    move(0, 5);
    for(a = 'A'; a < 'Z' + 1; a++) {
        addch(a);
        addstr(" ");
    }

    len = strlen(text);
    t = text;
    while(len) {
        move(5,5);
        insch(*(t+len-1));
        refresh();
        napms(100);
        len--;
    }

    getch();
    endwin();
    return 0;



}

int basic34() {
    char text[] = "Armstrong walks on moon!";
    char *t;
    int len;

    initscr();
    len = strlen(text);
    t = text;
    while(len) {
        move(5,5);
        insch(*(t+len-1));
        refresh();
        napms(100);
        len--;
    }
    getch();

    endwin();
    return 0;
}

int basic33() {

    char text1[] = "This is the first line\n";
    char text2[] = "Line two here\n";
    char text3[] = "The third line\n";
    char text4[] = "Fourth line here\n";
    char text5[] = "And the fifth line\n";

    initscr();

    addstr(text1);
    addstr(text3);
    addstr(text5);
    refresh();
    getch();

    move(1,0);
    insertln();
    refresh();
    getch();

    addstr(text2);
    refresh();
    getch();

    move(3,0);
    insertln();
    addstr(text4);
    refresh();
    getch();


    endwin();
    return 0;



}

int basic32() {
    char ch = '\0';
    int row, col;

    initscr();

    addstr("Type some text; '~' to end:\n");
    refresh();

    while((ch = getch()) != '~')
        ;

    getyx(stdscr, row, col);
    printw("\n\nThe cursor was at row %d, column %d when you stopped typing", row, col);

    refresh();
    getch();
    endwin();

    return 0;
}



int basic31() {
    initscr();

    char titles[3][40] = {
            "Penguin Soccer Finales",
            "Center Dung Samples from Temecula",
            "Why Do Ions Hate Each Other?"
    };

    center(1, titles[0]);
    center(5, titles[1]);
    center(9, titles[2]);
    getch();
    endwin();
    return 0;
}

void center(int row, char* title) {
    int len, indent, y, width;
    // get screen width
    getmaxyx(stdscr, y, width);
    // get title length
    len = strlen(title);
    // calculate indent
    indent = (width - len) / 2;
    // show the string
    mvaddstr(row, indent, title);
    refresh();
}

int basic30() {
    int lines, cols;

    initscr();
    getmaxyx(stdscr, lines, cols);
    lines--;
    cols--;

    mvaddch(0,0, '*');
    refresh();
    napms(500);

    mvaddch(0, cols, '*');
    refresh();
    napms(500);

    mvaddch(lines, 0, '*');
    refresh();
    napms(500);

    mvaddch(lines, cols, '*');
    refresh();

    getch();
    endwin();
    return 0;
}

int basic29(){
    int x,y;
    initscr();
    getmaxyx(stdscr, y, x);
    printw("Window is %d rows by %d columns.\n", y,x);
    printw("Window is %d rows by %d columns.\n", LINES,COLS);
    refresh();
    getch();
    endwin();
    return 0;

}

int basic28() {
    wchar_t hello[] = {
            0x014f, 0x0440, 0x0438,
            0x0432, 0x0435, 0x0442,
            0x0021, 0x0
    };
    setlocale(LC_CTYPE,"en_US.UTF-8");
    initscr();
    addwstr(hello);
    refresh();
    getch();

    endwin();
    return 0;

}

int basic27() {

    cchar_t heart = {
            A_NORMAL,
            L"\u2665"
    };
    setlocale(LC_CTYPE,"en_US.UTF-8");
    initscr();
    addstr("I ");
    add_wch(&heart);
    addstr(" Ncurses");
    refresh();
    getch();

    endwin();
    return 0;

}

int basic26() {
    char box[] = "lqk\nx x\nmqj\n";
    int x = 0;
    initscr();
    attrset(A_ALTCHARSET);
    addstr(box);
    refresh();
    getch();
    endwin();
    return 0;

}

int basic25() {
    chtype string[12] = {
            ACS_ULCORNER, ACS_HLINE, ACS_URCORNER, '\n',
            ACS_VLINE, ' ', ACS_VLINE, '\n',
            ACS_LLCORNER, ACS_HLINE, ACS_LRCORNER, '\n',
    };
    int x = 0;
    initscr();
    addchstr(string); //this does not work see next example
    refresh();
    getch();
    endwin();
    return 0;

}

int basic24() {
    chtype string[] = {
            'H' | A_BOLD,
            'e',
            'l' | A_REVERSE,
            'l' | A_REVERSE,
            'o',
            '!' | A_UNDERLINE,
            0
    };
    int x = 0;
    initscr();
    while (string[x]) {
        addch(string[x]);
        x++;
    }
    addch('\n');
    addchstr(string);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic23() {
    initscr();
    addch(ACS_ULCORNER);
    addch(ACS_HLINE);
    addch(ACS_URCORNER);
    addch('\n');
    addch(ACS_VLINE);
    addch(' ');
    addch(ACS_VLINE);
    addch('\n');
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);
    addch(ACS_LRCORNER);
    addch('\n');
    refresh();
    getch();
    endwin();

    return 0;
}

int basic22() {
    int a;
    initscr();
    for (a = 0; a < 127; a++) {
        printw("\t%2X:", a);
        addch(A_ALTCHARSET | a);
    }
    refresh();
    getch();
    endwin();
    return 0;
}

int basic21() {
    initscr();
    addch(A_ALTCHARSET | ACS_PI);
    addstr("= 3.14159");
    addch(A_ALTCHARSET | ACS_DARROW);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic20() {
    initscr();
    attrset(A_STANDOUT);
    addstr("This is A_STANDOUT\n");
    attrset(A_UNDERLINE);
    addstr("This is A_UNDERLINE\n");
    attrset(A_REVERSE);
    addstr("This is A_REVERSE\n");
    attrset(A_BLINK);
    addstr("This is A_BLINK\n");
    attrset(A_DIM);
    addstr("This is A_DIM\n");
    attrset(A_BOLD);
    addstr("This is A_BOLD\n");
    attrset(A_ALTCHARSET);
    addstr("This is A_ALTCHARSET\n");
    attrset(A_INVIS);
    addstr("This is A_INVIS\n");
    attrset(A_PROTECT);
    addstr("This is A_PROTECT\n");
    attrset(A_HORIZONTAL);
    addstr("This is A_HORIZONTAL\n");
    attrset(A_LEFT);
    addstr("This is A_LEFT\n");
    attrset(A_LOW);
    addstr("This is A_LOW\n");
    attrset(A_RIGHT);
    addstr("This is A_RIGHT\n");
    attrset(A_TOP);
    addstr("This is A_TOP\n");
    attrset(A_VERTICAL);
    addstr("This is A_VERTICAL\n");

    refresh();
    getch();
    endwin();
    return 0;

}

int basic19() {
    initscr();
    addch('c');
    addch(A_BOLD | 'a');
    addch(A_REVERSE | 't');
    refresh();
    getch();

    move(0, 2);
    addch('r');
    refresh();
    getch();

    endwin();
    return 0;


}

int basic18() {
    initscr();
    addch('c');
    addch(A_BOLD | 'a');
    addch(A_REVERSE | 't');
    refresh();
    getch();
    endwin();
    return 0;
}

int basic16() {
    initscr();
    addstr("Attention!\n");
    beep();
    refresh();
    getch();

    addstr("I said, ATTENTION!\n");
    flash();
    refresh();
    getch();

    endwin();
    return 0;
}

int basic15() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_GREEN);
    bkgd(COLOR_PAIR(1));

    addstr("I think I shall never see\n");
    addstr("For seasons may change\n");
    addstr("and storms may thunder;\n");
    addstr("But color text shall always wonder.");
    refresh();
    getch();

    bkgd(COLOR_PAIR(2));
    refresh();
    getch();

    bkgd(COLOR_PAIR(3));
    refresh();
    getch();

    endwin();
    return 0;


}


int basic14() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    // bkgd('.'); //you can also fill with a character
    // bkgd(COLOR_PAIR(1) | '.'); // or both things
    addstr("This is some text");
    refresh();
    getch();
    endwin();
    return 0;
}

int basic13() {
    initscr();
    start_color();
    if (!can_change_color()) {
        addstr("This probably won't work...\n");
    }
    init_color(PINK, 1000, 750, 750);
    init_pair(1, PINK, COLOR_BLACK);
    attrset(COLOR_PAIR(1));
    printw("This is the new color %d\n", PINK);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic12() {

    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attrset(COLOR_PAIR(1));
    addstr("I am Mr. Black!\n");
    attrset(COLOR_PAIR(2));
    addstr("I am Mr. Yellow!\n");
    attrset(COLOR_PAIR(1) | A_BOLD);
    addstr("I'm feeling bold!\n");
    attrset(COLOR_PAIR(2) | A_BOLD);
    addstr("Me too!");
    refresh();
    getch();
    endwin();
    return 0;
}

int basic11() {
    initscr();
    if (!has_colors()) {
        endwin();
        puts("Terminal cannot do colors");
        return 1;
    }
    if (start_color() != OK) {
        endwin();
        puts("Unable to start colors!");
        return 1;
    }
    printw("Colors initialized.\n");
    printw("%d colors available.\n", COLORS);
    printw("%d color pairs.", COLOR_PAIRS);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic10() {
    char text[COUNT][10] = {
            "Do", "you", "find", "this", "silly?"
    };
    int a, b;

    initscr();
    for (a = 0; a < COUNT; a++) {
        for (b = 0; b < COUNT; b++) {
            if (b == a)
                attrset(A_BOLD | A_UNDERLINE);
            printw("%s", text[b]);
            if (b == a)
                attroff(A_BOLD | A_UNDERLINE);
            addch(' ');
        }
        addstr("\b\n");
    }
    refresh();
    getch();
    endwin();
    return 0;
}


int basic09() {

    initscr();
    attron(A_BOLD);
    addstr("Twinkle, twinkle little star\n");
    attron(A_BLINK);
    addstr("How I wonder what you are.\n");
    attroff(A_BOLD);
    addstr("Up above the world so high,\n");
    addstr("Like a diamond in the sky.\n");
    attrset(A_NORMAL);
    addstr("Twinkle, twinkle little star\n");
    addstr("How I wonder what you are.\n");
    refresh();
    getch();
    endwin();
    return 0;
}

int basic08() {
    int pieces;
    const float uni = 4.5;
    initscr();
    addstr("SUSHI BAR");
    move(2, 0);
    printw("We have Uni today for $%.2f\n", uni);
    addstr("How many pieces would you like?");
    refresh();
    char int_conv[3] = "%d";
    scanw(int_conv, &pieces);
    printw("You want %d pieces?\n", pieces);
    printw("That will be $%.2f", uni * (float) pieces);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic07() {
    char first[24];
    char last[32];

    initscr();
    addstr("What is your first name? ");
    refresh();
    getnstr(first, 23);
    addstr("What is your last name? ");
    refresh();
    getnstr(last, 31);
    printw("Pleased to meet you, %s %s!", first, last);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic06() {
    int ch;
    initscr();
    addstr("Type a few lines of text\n");
    addstr("Press ~ to quit\n");
    refresh();

    while ((ch = getch()) != '~') {

    }
    endwin();
    return 0;
}

int basic05() {
    int yoda = 874;
    int ss = 65;

    initscr();
    printw("Yoda is %d years old\n", yoda);
    printw("He has collected %d years", yoda - ss);
    printw(" of Social security");
    refresh();
    getch();
    endwin();
    return 0;

}

int basic04() {
    char t1[] = "Shall I compare thee";
    char t2[] = "to a summer's day";
    initscr();
    addstr(t1);
    addstr(t2);
    move(2, 0); //row 3, column 1
    addstr("Though art more lovely...");
    refresh();
    getch();
    endwin();
    return 0;
}

int basic03() {
    char t1[] = "Shall I compare thee";
    char t2[] = "to a summer's day";
    initscr();
    addstr(t1);
    addstr(t2);
    refresh();
    getch();
    endwin();
    return 0;
}

int basic02() {
    char text[] = "Greetings from Ncurses!";
    char *t;

    initscr();
    t = text;
    while (*t) {
        addch(*t);
        t++;
        refresh();
        napms(100); //delays 1 sec
    }
    getch();
    endwin();
    return 0;
}

int basic01() {
    initscr();
    addstr("Good-bye, cruel world");
    refresh();
    getch();
    endwin();
    return 0;
}