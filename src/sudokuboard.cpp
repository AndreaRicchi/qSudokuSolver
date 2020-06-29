#include "sudokuboard.hpp"

#include <QGuiApplication>

SudokuBoard::SudokuBoard(const QVector<uint> &data, QObject *parent)
    : QObject(parent)
    , m_dimX(9)
    , m_dimY(9)
{
    m_data.resize(m_dimX * m_dimY);
    init(data);
}

void SudokuBoard::init(QVector<uint> data)
{
    auto dataIt = 0;

    for (auto i = 0; i < 9; ++i) {
        for (auto j = 0; j < 9; ++j) {
            operator()(i, j) = data[dataIt];
            ++dataIt;
        }
    }
    emit boardChanged();
}

std::pair<int, int> SudokuBoard::findEmpty()
{
    for (auto i = 0; i < 9; ++i) {
        for (auto j = 0; j < 9; ++j) {
            if (operator()(i, j) == 0) {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1);
}

uint &SudokuBoard::operator()(uint x, uint y)
{
    if (x >= m_dimX || y >= m_dimY) {
        throw std::out_of_range("board indices out of range");
    }
    return m_data[m_dimX * y + x];
}

bool SudokuBoard::isValid(uint number, uint x, uint y)
{
    if (operator()(x, y) != 0) {
        return false;
    }

    for (uint i = 0; i < 9; ++i) {
        if (operator()(i, y) == number && i != x) {
            return false;
        }
    }

    for (uint i = 0; i < 9; ++i) {
        if (operator()(x, i) == number && i != y) {
            return false;
        }
    }

    auto boxX = x / 3;
    auto boxY = y / 3;

    for (uint i = boxX * 3; i < (boxX * 3) + 3; ++i) {
        for (uint j = boxY * 3; j < (boxY * 3) + 3; ++j) {
            if (operator()(i, j) == number) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuBoard::solve()
{
    auto empty = findEmpty();
    if (empty.first == -1 && empty.second == -1) {
        return true;
    }

    for (auto i = 1; i < 10; ++i) {
        if (isValid(i, empty.first, empty.second)) {
            qApp->processEvents();
            operator()(empty.first, empty.second) = i;
            emit boardChanged();
            if (solve()) {
                return true;
            }
            operator()(empty.first, empty.second) = 0;
            emit boardChanged();
        }
    }

    return false;
}

QVariantList SudokuBoard::box1()
{
    return {
        operator()(0, 0),
        operator()(0, 1),
        operator()(0, 2),
        operator()(1, 0),
        operator()(1, 1),
        operator()(1, 2),
        operator()(2, 0),
        operator()(2, 1),
        operator()(2, 2),
    };
}

QVariantList SudokuBoard::box2()
{
    return {
        operator()(0, 3),
        operator()(0, 4),
        operator()(0, 5),
        operator()(1, 3),
        operator()(1, 4),
        operator()(1, 5),
        operator()(2, 3),
        operator()(2, 4),
        operator()(2, 5),
    };
}

QVariantList SudokuBoard::box3()
{
    return {
        operator()(0, 6),
        operator()(0, 7),
        operator()(0, 8),
        operator()(1, 6),
        operator()(1, 7),
        operator()(1, 8),
        operator()(2, 6),
        operator()(2, 7),
        operator()(2, 8),
    };
}

QVariantList SudokuBoard::box4()
{
    return {
        operator()(3, 0),
        operator()(3, 1),
        operator()(3, 2),
        operator()(4, 0),
        operator()(4, 1),
        operator()(4, 2),
        operator()(5, 0),
        operator()(5, 1),
        operator()(5, 2),
    };
}

QVariantList SudokuBoard::box5()
{
    return {
        operator()(3, 3),
        operator()(3, 4),
        operator()(3, 5),
        operator()(4, 3),
        operator()(4, 4),
        operator()(4, 5),
        operator()(5, 3),
        operator()(5, 4),
        operator()(5, 5),
    };
}

QVariantList SudokuBoard::box6()
{
    return {
        operator()(3, 6),
        operator()(3, 7),
        operator()(3, 8),
        operator()(4, 6),
        operator()(4, 7),
        operator()(4, 8),
        operator()(5, 6),
        operator()(5, 7),
        operator()(5, 8),
    };
}

QVariantList SudokuBoard::box7()
{
    return {
        operator()(6, 0),
        operator()(6, 1),
        operator()(6, 2),
        operator()(7, 0),
        operator()(7, 1),
        operator()(7, 2),
        operator()(8, 0),
        operator()(8, 1),
        operator()(8, 2),
    };
}

QVariantList SudokuBoard::box8()
{
    return {
        operator()(6, 3),
        operator()(6, 4),
        operator()(6, 5),
        operator()(7, 3),
        operator()(7, 4),
        operator()(7, 5),
        operator()(8, 3),
        operator()(8, 4),
        operator()(8, 5),
    };
}

QVariantList SudokuBoard::box9()
{
    return {
        operator()(6, 6),
        operator()(6, 7),
        operator()(6, 8),
        operator()(7, 6),
        operator()(7, 7),
        operator()(7, 8),
        operator()(8, 6),
        operator()(8, 7),
        operator()(8, 8),
    };
}
