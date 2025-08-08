import csv
import ftplib
import os
import subprocess


TR_TEMPLATE = """
<tr>
    <td style="padding: 8px;">DATE</td>
    <td style="padding: 8px;">
        <a href="FILE_NAME" style="font-weight: bold; font-size: 1.05em;">FILE_NAME</a>
    </td>
    <td style="padding: 8px;">FILE_SIZE</td>
    <td style="padding: 8px;">EXE</td>
</tr>
"""


def build_offline_installer(version):
    subprocess.run(
        [os.environ.get('ifw_location') + '/bin/binarycreator.exe', '--offline-only',
         '-c', 'prod_v4_src/config/config.xml', '-p', 'prod_v4_src/packages',
         'iRIC_Installer_{}_offline'.format(version)],
        check=True
    )


def update_versions_csv(version, release_date):
    filename = 'iRIC_Installer_{}_offline.exe'.format(version)
    file_size = os.path.getsize(filename) / 1048576
    file_size_str = '{:.2f} MB'.format(file_size)

    with open('versions.csv', 'a', encoding='utf-8') as f:
        f.write('{},{},{}\n'.format(version, release_date, file_size_str))


def update_index_html():
    versions_html = ''

    with open('versions.csv', 'r', encoding='utf-8') as f:
        reader = csv.reader(f)
        for row in reader:
            if len(row) == 3:
                filename = 'iRIC_Installer_{}_offline.exe'.format(row[0])
                versions_html += TR_TEMPLATE.replace('DATE', row[1]) \
                    .replace('FILE_NAME', filename) \
                    .replace('FILE_SIZE', row[2])

    with open('index_template.html', 'r', encoding='utf-8') as f:
        t = f.read()

    t = t.replace('VERSIONS', versions_html)

    with open('index.html', 'w', encoding='utf-8') as f:
        f.write(t)


def upload_to_ftp(version):
    FTP_HOST = "sv7500.xserver.jp"
    ID = "installer@i-ric.org"
    PASSWORD = os.environ.get('FTP_PASSWORD')

    ftp = ftplib.FTP(FTP_HOST)
    ftp.login(ID, PASSWORD)

    with open('index.html', 'rb') as f:
        ftp.storbinary('STOR index.html', f)

    installer_path = 'iRIC_Installer_{}_offline.exe'.format(version)

    with open(installer_path, 'rb') as f:
        ftp.storbinary('STOR {}'.format(installer_path), f)

    ftp.quit()


def main():
    version = os.environ.get('VERSION')
    release_date = os.environ.get('RELEASE_DATE')

    build_offline_installer(version)
    update_versions_csv(version, release_date)
    update_index_html()
    upload_to_ftp(version)


if __name__ == "__main__":
    main()
