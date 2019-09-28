    /*
    * Необходимо покрыть все возможные
    * и невозможные кейсы. Например,
    * convertBytesToHuman(-1) === false,
    * convertBytesToHuman(-1) !== '1 B',
    * convertBytesToHuman('string') === false
    * convertBytesToHuman(5) === '5 B'
    */

    import convertBytesToHuman from './convertBytesToHuman';

    test('Возвращает false для неправильного типа данных', () => {
    expect(convertBytesToHuman('String')).toBe(false);
    expect(convertBytesToHuman(' a101 ')).toBe(false);
    });

    test('Возвращает корректное значение для чисел', () => {
    expect(convertBytesToHuman(1)).toBe(1 B);
    expect(convertBytesToHuman(0)).toBe(0 B);
    expect(convertBytesToHuman(' 66 ')).toBe(66 B);
    expect(convertBytesToHuman(1024)).toBe(1 KB);
    expect(convertBytesToHuman('1')).toBe(1 B);
    expect(convertBytesToHuman(123123123)).toBe(117.42 MB);
    expect(convertBytesToHuman(1.1e12)).toBe(1.00 TB);
    });

    test('Возвращает false для отрицательных значений', () => {
    expect(convertBytesToHuman(-1)).toBe(false);
    });
