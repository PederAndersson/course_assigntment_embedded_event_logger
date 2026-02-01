# Embedded Event Logger

Detta projekt är en simulation av en inbäddad händelseloggare (Event Logger) skriven i C. Programmet använder olika datastrukturer och algoritmer för att hantera sensorhändelser i realtid.

## Funktioner

- **Datastrukturer**: Använder en cirkulär buffert (Queue) för temporär lagring och en länkad lista (EventLog) för permanent historik.
- **Designmönster**: Implementerar Observer-mönstret för notifieringar, Producer-Consumer för händelsehantering och Strategy/Command-mönster för användarinteraktion.
- **Sortering**: Inkluderar både Merge Sort och Insertion Sort.
- **Sökning**: Möjlighet att filtrera händelser baserat på sensor-ID.
- **Larm**: Automatiska larm triggas om sensorvärden överskrider förinställda gränsvärden.

## Hur man kör programmet

### Kompilering

Använd CMake för att konfigurera och bygga projektet:

```powershell
# Skapa en byggkatalog (valfritt, CLion skapar oftast cmake-build-debug)
cmake -B cmake-build-debug
# Bygg projektet
cmake --build cmake-build-debug --target course_assigntment
```

### Exekvering

Kör den genererade exekverbara filen:

```powershell
.\cmake-build-debug\course_assigntment.exe
```

## Tillgängliga kommandon

När programmet körs kan följande kommandon användas:

- `help`: Visar en lista över alla tillgängliga kommandon.
- `tick [antal]`: Genererar ett specifikt antal slumpmässiga händelser (t.ex. `tick 25`).
- `print`: Skriver ut hela händelseloggen.
- `sort [algoritm]`: Sorterar och skriver ut loggen. Tillgängliga algoritmer: `merge` eller `insertion`.
- `find [id]`: Hittar och skriver ut alla händelser för en specifik sensor med det angivna ID:t.
- `alarm`: Visar vilka sensorer som har aktiva larm.
- `quit`: Avslutar programmet och frigör allt minne.

## Exempel

Här är några exempel på hur du kan interagera med programmet:

### Skapa och visa händelser
```text
Input: tick 10
Input: print
```
Detta skapar 10 händelser och skriver ut dem på skärmen.

### Sortera loggen med Merge Sort
```text
Input: sort merge
```
Detta sorterar alla loggade händelser efter ID och värde med hjälp av Merge Sort-algoritmen.

### Söka efter en specifik sensor
```text
Input: find 3
```
Detta skriver ut alla loggade händelser som har Sensor ID: 3.

### Kontrollera larm
```text
Input: alarm
```
Om en temperatursensor (ID 1-5) har ett värde över 30, eller en fuktsensor (ID 6-10) över 60, kommer de att synas här.

### gitHub
```text
https://github.com/PederAndersson/course_assigntment_embedded_event_logger/tree/main
```
