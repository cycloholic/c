#include <iostream>
#include <chrono>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;
using namespace chrono;

void setBufferedInput(bool enable) {
    static bool enabled = true;
    static struct termios old;
    struct termios new_t;

    if (enable && !enabled) {
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        enabled = true;
    } else if (!enable && enabled) {
        tcgetattr(STDIN_FILENO, &new_t);
        old = new_t;
        new_t.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
        enabled = false;
    }
}

int main() {
    string quote = "The quick brown fox jumps over the lazy dog.";
    string input;
    cout << "📜 Type the following quote:\n\n";
    cout << quote << "\n\n";

    cout << "⏳ Press any key to start...\n";
    cin.get();

    setBufferedInput(false);
    auto start = steady_clock::now();

    char ch;
    size_t i = 0;
    int correct = 0;
    while (i < quote.length()) {
        ch = getchar();
        cout << ch << flush;

        input += ch;
        if (ch == quote[i])
            correct++;
        i++;
    }

    auto end = steady_clock::now();
    setBufferedInput(true);

    auto elapsed = duration_cast<duration<double>>(end - start).count();
    double wpm = (quote.length() / 5.0) / (elapsed / 60.0);
    double accuracy = (double)correct / quote.length() * 100.0;

    cout << "\n\n✅ Done!\n";
    cout << "⏱️ Time: " << elapsed << "s\n";
    cout << "🔤 Accuracy: " << accuracy << "%\n";
    cout << "🚀 WPM: " << wpm << "\n";

    return 0;
}
