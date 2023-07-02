#include "edit.h"

edit::edit()
{

    QXlsx::Document xlsx;
            //xlsx.setColumn(1, 4, 20.0);
            //xlsx.setColumnFormat(1,4,20.0);


            QXlsx::Format header;
            header.setFontBold(true);
            header.setFontSize(15);

            xlsx.setColumnWidth(1,4,20.0);
            xlsx.write(1, 1, "id", header);
            xlsx.write(1, 2, "firstname", header);
            xlsx.write(1, 3, "lastname", header);
            xlsx.write(1, 4, "sexe", header);
            xlsx.write(1, 5, "class", header);
            xlsx.write(1, 6, "filiere", header);
             xlsx.write(1, 7, "option", header);
              xlsx.write(1, 8, "yearAcademic", header);

            xlsx.saveAs("C:\\Users\\Public\\model1.xlsx");
            QUrl fileUrl = QUrl::fromLocalFile("C:\\Users\\Public\\model1.xlsx");
            QDesktopServices::openUrl(fileUrl);
}
