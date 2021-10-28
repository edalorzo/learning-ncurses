#define _XOPEN_SOURCE_EXTENDED 1

#include<ncurses.h>
#include<clocale>
#include<cstring>

#define COUNT 5
#define PINK 1

using namespace std;

void center(int row, char *title);
int kbhit();

int main() {
    WINDOW *second;

    initscr();
    start_color();

    /* configure colors*/
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    /* create the second window*/
    second = newwin(0,0,0,0);
    if(second == nullptr) {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(2));
    waddstr(second, "This is the second window");

    /* standard screen*/
    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press enter");
    refresh();
    getch();

    /* show second window*/
    wrefresh(second);
    getch();

    // show standard windows again
    touchwin(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}

// pop up a new window
int basic51() {

    WINDOW *another;

    initscr();
    addstr("This is the standard screen\n");
    refresh();
    getch();

    /* create another window */
    another = newwin(0,0,0,0);
    if(another == nullptr) {
        addstr("Unable to create window");
        refresh();
        getch();
    }
    else {
        waddstr(another, "This is another window");
        wrefresh(another);
        wgetch(another);
    }

    endwin();
    return 0;

    return 0;
}

// flushing input
int basic50() {
    char buffer[81];
    initscr();

    addstr("Type. I'll wait...\n");
    refresh();
    napms(5000); // 5 seconds

    addstr("Flushing buffer.\n");
    flushinp();
    addstr("Here is what you typed:\n");
    getnstr(buffer, 80);

    endwin();
    return 0;
}

// silent input e.g. for a password capture
int basic49() {
    char name[32];
    char password[32];

    initscr();

    addstr("Name: ");
    getnstr(name, 31);
    /* disable text output */
    noecho();
    addstr("Password: ");
    getnstr(password, 31);
    /* enable text output */
    echo();
    printw("%s's password is '%s'", name, password);
    refresh();
    getch();
    endwin();

    return 0;
}

// using the keypad function to test characters pressed
int basic48() {

    int ch;

    initscr();
    keypad(stdscr, TRUE);
    do {
        ch = getch();
        switch (ch) {
            case KEY_DOWN:
                addstr("Down\n");
                break;
            case KEY_UP:
                addstr("Up\n");
                break;
            case KEY_LEFT:
                addstr("Left\n");
                break;
            case KEY_RIGHT:
                addstr("Right\n");
                break;
            default:
                break;
        }
        refresh();
    } while (ch != '\n');

    endwin();
    return 0;


}

// using th kbhit function to unread a character
int basic47() {
    int x;

    initscr();
    addstr("Tap a key while I count....\n");
    for (x = 1; x < 21; x++) {
        printw("%d ", x);
        refresh();
        napms(500);
        if (kbhit()) {
            break;
        }
    }
    addstr("\nDone!\n");
    printw("You pressed the '%c' key\n", getch());
    refresh();
    getch();

    endwin();
    return 0;

}


// check the keyboard queue
int kbhit() {
    int ch, r;

    // turn off blocking and echo
    nodelay(stdscr, TRUE);
    noecho();

    // check for input
    ch = getch();
    if (ch == ERR) // no input
        r = FALSE;
    else {
        r = TRUE;
        // return key to the queue
        ungetch(ch);
    }
    // restore block and echo
    echo();
    nodelay(stdscr, FALSE);
    return r;
}

/**
 * getch does not echo
 */
int basic46() {
    int key1, key2;
    initscr();

    addstr("Type a key: ");
    refresh();
    key1 = getch();
    clear();

    addstr("Type the same key: ");
    noecho();
    key2 = getch();
    move(1, 0);
    if (key1 == key2) {
        addstr("The keys match");
    } else {
        addstr("The keys don't match");
    }
    getch();
    refresh();

    endwin();
    return 0;

}


/**
 * getch does not block
 */
int basic45() {
    int value = 0;

    initscr();

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    /* turn off get blocking */
    nodelay(stdscr, TRUE);
    addstr("Press any key to stop the loop!\n");
    while (getch() == ERR) {
        printw("%d\r", value++);
        refresh();
    }

    endwin();
    return 0;

}


int basic42() {
    char name[32];
    int ch;

    initscr();
    do {
        clear();
        addstr("Enter your name: ");
        getnstr(name, 32);
        move(1, 0);
        printw("Your name is %s. ", name);
        printw("Is this correct? ");
        ch = getch();
    } while (ch != 'y');
    move(2, 0);
    printw("Pleased to you, %s\n", name);
    getch();

    endwin();
    return 0;
}

int basic41() {
    int c, y, x, cmax;

    initscr();
    getmaxyx(stdscr, y, x);
    cmax = (x * y / 5);
    cmax = (x * y / 5);
    for (c = 0; c < cmax; c++) {
        addstr("blah");
    }
    getch();

    move(5, 20);
    //clrtoeol(); // clear to end of line
    clrtobot(); // clear to bottom
    refresh();
    getch();

    endwin();
    return 0;


}

int basic40() {
    int c, y, x, cmax;

    initscr();
    getmaxyx(stdscr, y, x);
    refresh();
    cmax = (x * y / 5);
    for (c = 0; c < cmax; c++) {
        addstr("blah");
    }
    getch();

    clear();
    refresh();
    getch();

    endwin();
    return 0;

}

int basic39() {
    int row, col;

    initscr();

    for (row = 0; row < LINES; row++) {
        for (col = 0; col < COLS; col++) {
            addch('.');
        }
    }
    refresh();
    getch();

    move(5, 0);
    insdelln(3);
    refresh();
    getch();

    insdelln(-5);
    refresh();
    getch();

    endwin();
    return 0;
}

int basic38() {
    int x;

    initscr();
    addstr("This is the first line\n");
    addstr("Line two here\n");
    addstr("The third line\n");
    addstr("Fourth line here\n");
    addstr("And the fifth line\n");
    refresh();
    getch();

    move(3, 7);
    for (x = 0; x < 5; x++) {
        delch();
        refresh();
        napms(250);
    }
    getch();
    endwin();
    return 0;
}

int basic37() {
    initscr();

    // add fine lines
    addstr("This is the first line\n");
    addstr("Line two here\n");
    addstr("The third line\n");
    addstr("Fourth line here\n");
    addstr("And the fifth line\n");
    refresh();
    getch();

    // remove a line
    move(2, 0);
    deleteln();
    refresh();
    getch();

    endwin();
    return 0;
}


int basic36() {
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

    move(1, 0);
    insertln();
    insstr(text2);
    refresh();
    getch();

    move(3, 0);
    deleteln();
    refresh();
    getch();

    endwin();
    return 0;
}


int basic35() {
    char text[] = "Armstrong walks on moon!";
    char *t;
    char a;
    size_t len;

    initscr();
    move(0, 5);
    for (a = 'A'; a < 'Z' + 1; a++) {
        addch(a);
        addstr(" ");
    }

    len = strlen(text);
    t = text;
    while (len) {
        move(5, 5);
        insch(*(t + len - 1));
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
    size_t len;

    initscr();
    len = strlen(text);
    t = text;
    while (len) {
        move(5, 5);
        insch(*(t + len - 1));
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

    move(1, 0);
    insertln();
    refresh();
    getch();

    addstr(text2);
    refresh();
    getch();

    move(3, 0);
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

    while ((ch = getch()) != '~');

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

void center(int row, char *title) {
    size_t len, indent;
    int y, width;
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

    mvaddch(0, 0, '*');
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

int basic29() {
    int x, y;
    initscr();
    getmaxyx(stdscr, y, x);
    printw("Window is %d rows by %d columns.\n", y, x);
    printw("Window is %d rows by %d columns.\n", LINES, COLS);
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
    setlocale(LC_CTYPE, "en_US.UTF-8");
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
    setlocale(LC_CTYPE, "en_US.UTF-8");
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

//TODO: This one didn't work for me! Why?
int basic24() {
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

int basic23() {
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

int basic22() {
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

int basic21() {
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

int basic20() {
    initscr();

    addch(A_ALTCHARSET | ACS_PI);
    addstr("= 3.14159");

    addch(A_ALTCHARSET | ACS_DARROW);
    refresh();

    getch();
    endwin();
    return 0;
}

int basic19() {

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

int basic18() {

    initscr();

    addch('c');
    addch(A_BOLD | 'a');
    addch(A_REVERSE | 't');
    addch('s' | A_BLINK);
    addch('\n');
    refresh();
    getch();

    move(0, 2);
    addch('r');
    move(1, 0);
    refresh();

    getch();

    endwin();
    return 0;


}

int basic17() {
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
    // COLORES ARE WORKING YAY!!!
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
    addstr("How many pieces would you like? ");
    refresh();
    char int_conv[3] = "%d";
    scanw(int_conv, &pieces);
    printw("You want %d pieces\n", pieces);
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

    while ((ch = getch()) != '~') { ;
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
    char t1[] = "Shall I compare thee ";
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
    char t1[] = "Shall I compare thee ";
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
    char text[] = "Greetings from Ncurses!"; //null-terminated string
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