# Keyword `const`
* keine spätere Veränderung mehr möglich  

         const int pi = 3;

* Compiler gibt Fehler bei Änderungsversuch
* Kann auch als Funktionsparameter verwendet werden  

        int square (const int* val)     // ergibt hier keinen Sinn...

* konstante Speicheradresse: `int* const ptr = &val;`
* Zeiger auf konstante Variable: `const int* ptr = &val;`
    > _`const` immer von rechts nach links lesen_

# Call bei Reference
* Gefahren beachten! (siehe Vorlesung)
* Übergabe von Pointern oder Referenzen als Funktionenparametern ist häufig
  effizienter als die Übergabe der Objekte
* Eigenschaften siehe Vorlesung
* **NACHZULESEN: Syntax von Pointern und Referenzen**
    > _Referenzen wenn möglich - Zeiger wenn nötig_

# Objekte und Klassen
* Konvention: _Eine Datei pro Klasse & eine Klasse pro Datei_
* **WICHTIG:** Klassen-Deklaration endet mit Semicolon!
* Deklaration in Header-Datei, Implentierung in cpp-Datei
* Zugriff auf Objekte: Unterschied Objekt (Punkt) und Zeiger auf Objekt (Pfeil)
* Zugriffsstufen: `private` nur für Zugriff innerhalb der eigenen Klasse  
    und `public` für freie Zugriff auch außerhalb

# Operator Overloading
* Schema siehe Vorlesung
* Keyword `const` am Ende der Methode weist aus, dass diese Methode das Objekt
  nicht ändert 
  Wird das doch versucht, gibt der Compiler eine Warnung
* *Ein* Parameter wird als konstante Referenz übergeben

# Konstruktoren
* wird automatisch generiert, wenn _keiner_ deklariert wurde
* um den Standardkonstruktor trotzdem zu behalten, schreibe: 

        // standardkonstruktor
        robot::robot()
        {
        }

        // überladener konstruktor
        robot::robot(int param1, int param2, ...)
        {
            // some code here
        }

# Initialisierungslisten
* zur vermeidung von Compiler-Fehlern aufgrund konstanter Attribute

        // Konstuktor
        robot::robot(hand& connectedHand, int num) :
                m_rightHand(connectedHand), m_numHands(num) {}

# Defaultparameter
* optionale Parameter statt Überladung
* **Frage**: Angabe des Standardwertes nur in der Deklaration oder auch in der
  Implementierung?

# Konstante Funktionen
* Konstante Referenz als Rückgabewert nur bei getter-Funktionen um Fehler zu
  vermeiden
* `const` als Zusatz zur Funktionendeklaration garaniert, dass Klassenattribute
  nicht verändert werde
> _Was nicht verändert werden soll, sollte nicht veränderbar sein!_
* Beispiel siehe Vorlesung
