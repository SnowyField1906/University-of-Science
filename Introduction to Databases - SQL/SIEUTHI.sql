﻿CREATE DATABASE QLBHST
GO
USE QLBHST
GO
CREATE TABLE SANPHAM
(
    MASANPHAM char(5),
    TEN nvarchar(30),
    GIATIEN int,
    SOLUONGTON int,
    DONVITINH nvarchar(10),
    MALOAI char(1)

    CONSTRAINT PK_SANPHAM
    PRIMARY KEY(MASANPHAM)
)

CREATE TABLE LOAISANPHAM
(
    MALOAI char(1),
    TENLOAI nvarchar(30)

    CONSTRAINT PK_LOAISANPHAM
    PRIMARY KEY(MALOAI)
)

CREATE TABLE KHACHHANG
(
    MAKH char(5),
    HOTEN nvarchar(30),
    DIACHI nvarchar(30),
    DIENTHOAI nvarchar(15),
    NAMSINH date,
    GIOITINH nchar(3) CHECK (GIOITINH IN (N'Nam', N'Nữ'))

    CONSTRAINT PK_KHACHHANG
    PRIMARY KEY(MAKH)
)

CREATE TABLE HOADON
(
    MAHOADON char(5),
    NGAYLAP date,
    MAKH char(5)

    CONSTRAINT PK_HOADON
    PRIMARY KEY(MAHOADON)
)

CREATE TABLE CHITIETHOADON
(
    MAHOADON char(5),
    MASANPHAM char(5),
    SOLUONG int,
    DONGIA int 
    
    CONSTRAINT PK_CHITIETHOADON
    PRIMARY KEY(MAHOADON, MASANPHAM)
)

ALTER TABLE SANPHAM ADD 
    CONSTRAINT FK_SANPHAM_LOAISANPHAM FOREIGN KEY (MALOAI) REFERENCES LOAISANPHAM(MALOAI)

ALTER TABLE HOADON ADD 
    CONSTRAINT FK_HOADON_KHACHHANG FOREIGN KEY (MAKH) REFERENCES KHACHHANG(MAKH)

ALTER TABLE CHITIETHOADON ADD 
    CONSTRAINT FK_CHITIETHOADON_SANPHAM FOREIGN KEY (MASANPHAM) REFERENCES SANPHAM(MASANPHAM),
    CONSTRAINT FK_CHITIETHOADON_HOADON FOREIGN KEY (MAHOADON) REFERENCES HOADON(MAHOADON)

INSERT INTO LOAISANPHAM VALUES('A', N'Đồ dùng')
INSERT INTO LOAISANPHAM VALUES('B', N'Đồ dùng')
INSERT INTO LOAISANPHAM VALUES('C', N'Đèn điện')

INSERT INTO SANPHAM VALUES('SP01', N'Bột giặt Omo', 30, 70, N'túi', 'A')
INSERT INTO SANPHAM VALUES('SP02', N'Bột giặt Tide', 25, 200, N'túi', 'A')
INSERT INTO SANPHAM VALUES('SP03', N'Đèn bàn Rạng Đông', 100, 90, N'cái', 'C')
INSERT INTO SANPHAM VALUES('SP04', N'Nồi cơm điện SHARP 3041', 2500, 10, N'cái', 'B')
INSERT INTO SANPHAM VALUES('SP05', N'Bàn chải đánh răng PS', 12, 12, N'cái', 'A')
INSERT INTO SANPHAM VALUES('SP06', N'Nồi cơm điện PANASONIC 2097', 2000, 8, N'cái', 'B')
INSERT INTO SANPHAM VALUES('SP07', N'Bàn chải đánh răng Colgate', 16, 100, N'cái', 'A')

INSERT INTO KHACHHANG VALUES('KH01', N'Nguyễn Thanh Tùng', N'Hồ Chí Minh', '9-9091-2233', '1984', N'Nam')
INSERT INTO KHACHHANG VALUES('KH02', N'Lê Nhật Nam', N'Hồ Chí Minh', '9-9091-2233', '1972', N'Nữ')
INSERT INTO KHACHHANG VALUES('KH03', N'Nguyễn Thị Thanh', N'Cà Mau', '9-9091-2233', '1981', N'Nữ')
INSERT INTO KHACHHANG VALUES('KH04', N'Lê Thị Lan', N'Bình Dương', '9-9091-2233', '1984', N'Nữ')
INSERT INTO KHACHHANG VALUES('KH05', N'Trần Minh Quang', N'Đồng Nai', '9-9091-2233', '1984', N'Nam')
INSERT INTO KHACHHANG VALUES('KH06', N'Lê Văn Hải', N'Hồ Chí Minh', '9-9091-2233', '1970', N'Nam')
INSERT INTO KHACHHANG VALUES('KH07', N'Dương Văn Hai', N'Đồng Nai', '9-9091-2233', '1988', N'Nam')

INSERT INTO HOADON VALUES('HD01', '2011-03-20', 'KH01')
INSERT INTO HOADON VALUES('HD02', '2011-02-15', 'KH02')
INSERT INTO HOADON VALUES('HD03', '2011-01-18', 'KH05')
INSERT INTO HOADON VALUES('HD04', '2011-09-16', 'KH01')
INSERT INTO HOADON VALUES('HD05', '2011-02-27', 'KH02')

INSERT INTO CHITIETHOADON VALUES('HD01', 'SP01', 2, 30)
INSERT INTO CHITIETHOADON VALUES('HD01', 'SP02', 2, 25)
INSERT INTO CHITIETHOADON VALUES('HD02', 'SP01', 3, 30)
INSERT INTO CHITIETHOADON VALUES('HD03', 'SP02', 3, 25)
INSERT INTO CHITIETHOADON VALUES('HD03', 'SP03', 1, 90)
INSERT INTO CHITIETHOADON VALUES('HD03', 'SP01', 3, 30)
INSERT INTO CHITIETHOADON VALUES('HD04', 'SP04', 1, 2400)
INSERT INTO CHITIETHOADON VALUES('HD05', 'SP06', 1, 2000)
INSERT INTO CHITIETHOADON VALUES('HD05', 'SP01', 5, 30)