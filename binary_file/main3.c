#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    setlocale(LC_ALL, "");
    wchar_t text[100];
    wprintf(L"%lld", sizeof text);
    wprintf(L"Введите русский текст: ");
    fgetws(text, 100, stdin);
    wprintf(L"Вы ввели: %ls", text);
    return 0;
}