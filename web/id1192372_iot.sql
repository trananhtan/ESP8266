-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Máy chủ: localhost:3306
-- Thời gian đã tạo: Th3 14, 2018 lúc 12:44 PM
-- Phiên bản máy phục vụ: 10.2.12-MariaDB
-- Phiên bản PHP: 7.0.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `id1192372_iot`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `Room1`
--

CREATE TABLE `Room1` (
  `Stt` int(11) NOT NULL,
  `Ten` text COLLATE utf8_unicode_ci NOT NULL,
  `NEW` int(11) NOT NULL,
  `Old` int(11) NOT NULL,
  `App` int(11) NOT NULL,
  `Time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Đang đổ dữ liệu cho bảng `Room1`
--

INSERT INTO `Room1` (`Stt`, `Ten`, `NEW`, `Old`, `App`, `Time`) VALUES
(1, 'Led1', 1, 1, 0, '2018-03-14 00:00:00'),
(2, 'Led2', 1, 1, 0, '2018-03-14 00:00:00'),
(3, 'Fan', 1, 1, 0, '2018-03-14 00:00:00'),
(3, 'Fan', 1, 1, 0, '2018-03-14 00:00:00'),
(4, 'Motor', 1, 1, 0, '2018-03-14 00:00:00'),
(5, 'NhietDo', 25, 26, 0, '2018-03-14 00:00:00'),
(6, 'DoAm', 89, 98, 0, '2018-03-14 00:00:00');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `Room2`
--

CREATE TABLE `Room2` (
  `Stt` int(11) NOT NULL,
  `Ten` text COLLATE utf8_unicode_ci NOT NULL,
  `New` int(11) NOT NULL,
  `Old` int(11) NOT NULL,
  `Time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `Sound`
--

CREATE TABLE `Sound` (
  `Stt` int(11) NOT NULL,
  `Ten` text COLLATE utf8_unicode_ci NOT NULL,
  `NEW` int(11) NOT NULL,
  `Old` int(11) NOT NULL,
  `Time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
