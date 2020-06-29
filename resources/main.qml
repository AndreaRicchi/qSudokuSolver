import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Sudoku Solver")

    Grid {
        id: grid

        columns: 3
        rows: 3
        width: parent.width
        height: parent.height - 50

        anchors {
            top: parent.top
        }

        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box1
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box2
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box3
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box4
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box5
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box6
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box7
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box8
        }
        SudokuBox {
            width: parent.width / 3
            height: parent.height / 3
            values: board.box9
        }
    }

    Button {
        id: solveBtn

        width: 150
        height: 50
        text: "Solve"
        onClicked: board.solve()

        anchors {
            top: grid.bottom
            topMargin: 5
            horizontalCenter: parent.horizontalCenter
        }
    }
}
