#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <QObject>
#include <QVariantList>
#include <QVector>

class SudokuBoard : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList box1 READ box1 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box2 READ box2 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box3 READ box3 NOTIFY boardChanged)

    Q_PROPERTY(QVariantList box4 READ box4 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box5 READ box5 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box6 READ box6 NOTIFY boardChanged)

    Q_PROPERTY(QVariantList box7 READ box7 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box8 READ box8 NOTIFY boardChanged)
    Q_PROPERTY(QVariantList box9 READ box9 NOTIFY boardChanged)

public:
    explicit SudokuBoard(const QVector<uint> &data = QVector<uint>(), QObject *parent = nullptr);

    void init(QVector<uint> data);

    uint &operator()(uint x, uint y);

    std::pair<int, int> findEmpty();

    void print();

    bool isValid(uint number, uint x, uint y);

    Q_INVOKABLE bool solve();

    QVariantList box1();
    QVariantList box2();
    QVariantList box3();

    QVariantList box4();
    QVariantList box5();
    QVariantList box6();

    QVariantList box7();
    QVariantList box8();
    QVariantList box9();

signals:
    void boardChanged();

private:
    QVector<uint> m_data;
    uint m_dimX, m_dimY;
};

#endif // SUDOKUBOARD_HPP
