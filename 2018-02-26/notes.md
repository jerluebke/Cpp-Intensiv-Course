# Ablauf  
*   1 h Vorlesung
*   Rest des Tages bis 17 Uhr Übung  
... Pausen nach eigenem Ermessen
*   10 Einheiten zu je 8 h
*   Es können 3 Tage _entschuldigt_ gefehlt werden

# Compiler und Linker
*   der _Compiler_ übersetzt .cpp-Dateien in .obj-Dateien
*   der _Linker_ bündelt die .obj-Dateien zu einem ausführbaren Programm
*   **Fehlermeldungen**  
..* Beginnend mit C: Compiler-Fehler  
..* Beginnend mit L: Linker-Fehler  
*   zu jeder .cpp-Datei gibt es meist eine Header-Datei (.h)
*   .h-Dateien enthalten **Deklarationen**
*   die zugehörigen .cpp-Dateien enthalten die **Implementierungen**

# Bibliotheken
*   Compilerter Code
*   besteht aus zwei Teilen:  
..1.    die eigentliche Bibliothek (Windows: .lib, .dll; Linux: .a, .so)
..2.    die Deklarationen zu der Bibliothek (die zugehörige Header-Datei)

# Präprozessor
*   Geht Code vor compilierung durch und verarbeitet Macros
*   `#include "datei"` wird durch den Inhalt von `datei` ersetzt; wird zuerst
    im aktuellen Projekt gesucht
*   `# include <datei>` wird durch den Inhalt von `datei` ersetzt; wird im
    Include-Suchpfad gesucht (für Header von Fremdbibliotheken)
*   Definition von Konstanten:  `#define NAME VALUE`
*   Bedingte compilierung mit `#ifdef`, `ifndef`, `#else` und `#endif` falls
    Definition vorhanden ist
*   **NACHLESEN: Include-Guards**

# Variablen und Funktionen
    int a;
    int b = 7;
    int c = f(b);

---

    int f(int x);   // Deklaration von f

    int f(int x)    // Implementierung von f
    {
        return x*(1-x);
    }

# Datentypen
*   `void` - kein Wert
*   `bool` - 1 Byte
*   `char` - 8 Bit
*   `int`  - 32 Bit  
... Modifikationen: `unsigned, short, long, long long`
*   `float` - 32 Bit; `double` - 64 Bit
*   C-Strings: `char s[256] = "Hello World";` - char-Array
*   C++-Strings: `string s = "Hello World";` - String-Objekt
*   `int*` - Zeiger (Speicheradresse)
*   `int&` - Referenz (anderer Name einer Variablen)
*   `nullptr` - Konstante, ungültiger Zeiger
*   Aufzälungen: `enum FileFormat {wav, mp3, ogg}`
*   **NACHLESEN: C-Arrays, STL-Cotainer**
*   Alias für Typen: `typedef Typ Name;`

# Kontrollstrukturen
*   das meiste funktioniert wie Java
*   if-else, switch-case
*   for- und while-Schleifen

# Programm-Parameter
    int main(int argc, char** argv)
    {
        ...
        return 0;
    }

*   `argc`: _argument count_ - Anzahl der Parameter +1
*   `argv`: _argument values_
*   `char**`: Zeiger auf Zeiger auf char (-> Zeiger auf String unbekannter
    Länger)
*   `argv[0]` ist der Programmname, `argv[1]` ist der erste Paramter

# Konsolen-Interface
*   `cin, cout, cerr` - Datenströme
*   `endl` gibt '\n' aus und leert den Datenstrom (flush)
*   flush ohne newline: **Nachlesen**

# Casting
    int a = 3;
    double b = a;       // implizit
    double c = 3.7;
    int d = c;          // implizit, gibt Warnung
    int e = (int) c;    // explizit, rundet immer ab (hier: e = 3)
    int f = int (c);    // explizit, neue Syntax
    int g = int(round(c));  // g = 4
    bool b1 = 17;       // 0 -> False, sonst -> True
    bool b2 = nullptr;  // False, alle anderen Zeiger -> True

*   **ZU VERMEIDEN:** Zeiger nach Integer und zurück, Zeiger auf 64bit-Systemen
    passen nicht zu `int`!
