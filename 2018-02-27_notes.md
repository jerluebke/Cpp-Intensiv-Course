# Gültigkeitsbereiche und Namensräume
    bool bar = true;
    namespace foo
    {
        int bar = 7;
    }
    using namespace foo;
    cout << bar;        // Fehler -> Welche Variable?!
    cout << ::bar;      // true;
    cout << foo::bar    // 7;

*   `namespace std` ist die C++-Standardbiblothek
*   `using namespace std;` importiert alle Namen der Standardbiblothek

# Statische Arrays und Strings
    int v[100];         // Deklaration
    v[7] = 13;          // Wert schreiben
    cout << v[7] << endl;   // 13;
    double matrix[10][7]    // mehrdimensionaler Array
    double values[3] =
        {.1, .2, .3};       // Array-Konstante
    double matrix[2][2] = {
        {1, 2},
        {3, 1}
    };
    char str[10] = "b - some string"
    // str[0] = 'b' = 98;
    // etc...  

* Der Operator `sizeof` gibt die Größe von Typen in Bytes (auch bei Arrays)
    cout << sizeof(char);       // 1
    cout << sizeof(int);        // 4

    int i = 0;
    cout << sizeof i;           // 4, Klammern können bei Variablen weggelassen
                                // werden

    int arr[5] = {1, 2, 3, 4, 5}
    //**Nachzulesen**
    size_t numElems = sizeof(arr)/sizeof(int);

# Referenzen, Zeiger und Zeigerarithmetik
    int a = ;
    int* p = &a;        // type* -> Zeiger; &value -> Adresse, Referenz

* Eine Funktion, die eine Variable modifiziert:
    int square(int val)
    {
        val *= val;
        return val;
    }
    int i = 7;
    int res = square(i);        // res = 49

* Variante mit Referenz:
    int square(int& val)
    {
        val *= val;             // "semantisch falsch", aber legal
        return val;
    }
    int = 7;
    int res = square(i);        //!!! i = 49; res = 49;
    
* Ein Zeiger ist eine Speicheradresse
    int a = 0;
    int* p = &a;            // s.o.
    int** pp = &p;          // Zeiger auf Zeiger
    *p = 7;                 // a=7; *pointer -> Wert der Adresse

* Funtion mit Zeiger:
    int square(int* val)
    {
        (*val) *= (*val);
        return (*val);
    }
    int i = 7;
    int res = square(&i);   // !!! i = 49; res = 49;

* Unterschiede Zeiger - Referenz:
    char a = 0, b = 42;

    char* p = &a;           // Zeiger auf a
    char& r = a;            // Referenz auf a

    *p  = 7;                // a = 7
    r = 8;                  // a = 8

    p = &b;                 // *p = 42
    r = b;                  // a = 42; Referenz ist an Wert der Variable gebunden

    sizeof(p);              // 4
    sizeof(r);              // 1

* Zeigerarithmetik in Arrays:
    int a[4] = {2, 3, 5, 7};
    int* p = a;             // p = &a[0] (erstes Element)
    *p = 13;                // a = {13, ...}
    p[0] = 13;              // semantisch identisch
    p++;                    // erhöhe p (um einen int, 4 Byte)
    // dann:
    *p = 17;                // a = {13, 17, ...}
    p += 10;                // p = &a[11] ist ungültige Adresse!
    
# Anwendung der Zeigerarithmetik
    double v[100];
    for (int i = 0; i<100; i++)
        v[i] = 3.14159;         // Zugriff auf Indizes
    for (double* p=v; p!=v+100; p++)
        *p = 3.14159;           // Zugriff mittels Zeiger

* verwende Zeiger wie unbeschränkten Array
* es muss manuell sichergestellt werde, dass nicht über das Ende des Arrays
  hinausgeschrieben wird
* Addition/Subtraktion erlauben Navigation in Array

**Nachzulesen: Zeiger und Arrays**


# Speicherverwaltung
* globale Variablen existieren für die ganze Laufzeit des Programms
* Lokale Variablen liegen auf dem Stack. Ihr Speicherplatz wird freigegeben,
  wenn die Funktion verlassen wird
* keine Garbage-Collection!
  Jeder mit `new` angeforderte Speicher muss mit `delete` wieder freigegeben
  werden!
* Beispiel:
    int n = strtol(argv[1], NUL, 10);       // User input
    double* arr = new double[n];
    for (int i=0; i<n; i++)
        arr[i] = i*i;
    delete [] arr;  

**Nachzulesen: Speicherverwaltung**

# String
* Operatoren siehe Vorlesung
* Beachte Escape-Sequenzen (Maskierung mit `\`)
  Beispiele siehe Vorlesung

# Vektor
* Methoden und Anwendungsbeispiel siehe Vorlesung
