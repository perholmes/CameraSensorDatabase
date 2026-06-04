# Camera Sensors

The job is to download spec sheets for cinema and DSLR cameras, and produce a database of camera sensor widths and heights for each camera in each format it's able to shoot. We're interested in all sensors that can be used for shooting a movie, a TV show, or a YouTube show, so we're not specifically limited to cinema cameras.

The output should be a CSV file with the following columns:
* Manufacturer
* Camera
* Format
* Width
* Height

The purpose of the format field is that different formats might crop the sensor differently, resulting in different effective sensor sizes and thus focal length in calculations. For example, a sensor might be 6000 pixels across, but in a certain format, it only uses 5140 of the pixels, in order to avoid having to scale image data in-camera. If the sensor had a width of 30 mm before, its effective width is now 5140 / 6000 = 25.8 mm.

You must stay alert to whether a certain format crops the sensor to achieve the format, or if it scales the full sensor down to achieve the format. When the full sensor is being utilized and just scaled down, we need to show the full sensor size, even if the capture format is much smaller.

Widths and heights are in millimeters.

When there's only one format for a manufacturer and camera composite key, call the format Standard.

We want an exhaustive list that uses one line in the CSV for every combination of Manufacturer, Camera and Format, even if it gets repetitive. Do not merge any camera types together just because they have the same formats. And do not merge any formats, even if they have the same effective sensor size. All of this will be put into hierarchical menus in a user interface, where it will be confusing if every item isn't listed independently.

The output file should be called "camerasensors.csv". The column names should be in the first row, in lower case.

If an existing camerasensors.csv file exists, it should be updated with newly discovered camera or formats. It's critical to retain all cameras and formats that are already listed in the file, and there's no need to recalculate the same format, although it's worthwhile to discover if the cameras now support more formats that may affect effective sensor size. The CSV file should remain sorted by manufacturer, camera, and format, in that order.

Various resources have been manually downloaded in the Resources folder, such as cropping guides for Arri/Panavision cameras and more.

If any PDFs or HTML pages or CSV files are downloaded during the investigation, they should be placed into the Downloaded directory, so they can remain part of the project. Only download spec sheets from camera manufacturers, or that appear to come from manufacturers. Do not download spec sheets that are created and hosted by end-users, and respect their copyrights.



