-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: cis-350
-- ------------------------------------------------------
-- Server version	5.7.19-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tasks_1`
--

DROP TABLE IF EXISTS `tasks_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tasks_1` (
  `task_id` int(11) NOT NULL AUTO_INCREMENT,
  `subject` varchar(45) DEFAULT NULL,
  `start_date` date DEFAULT NULL,
  `end_date` date DEFAULT NULL,
  `description` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`task_id`)
) ENGINE=InnoDB AUTO_INCREMENT=43 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tasks_1`
--

LOCK TABLES `tasks_1` WRITE;
/*!40000 ALTER TABLE `tasks_1` DISABLE KEYS */;
INSERT INTO `tasks_1` VALUES (1,'SQL','0000-00-00','0000-00-00','Database'),(2,'DatabaseManagement','2017-06-10','2017-08-10','coding sql'),(3,'MSK TEST','1990-04-16','2017-04-16','MSK Test of Task Adding'),(4,'SQL','0000-00-00','0000-00-00','Database'),(5,'testTaks','1994-12-15','1994-12-16','birth of someone'),(6,'Learn MySQL INSERT','2010-01-01','2010-01-02','Start learning..'),(7,'New Baltimore Orioles player','2017-11-01','2018-11-01','LHP'),(8,'MSK TEST','1990-04-16','2017-04-16','MSK Test of Task Adding'),(9,'STUFF','2010-10-10','2010-10-11','DO THE THING'),(10,'construct an insert statement','2001-03-31','2018-05-13','here we go'),(11,'Learn MySQL INSERT','2010-01-01','2010-01-02','Start learning..'),(12,'Learn MySQL INSERT','2010-01-01','2010-01-02','Start learning..'),(13,'Learn MySQL INSERT','2010-01-01','2010-01-02','Start learning..'),(14,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(15,'Learn MySQL INSERT','2010-01-01','2010-01-02','Start learning..'),(16,'BigWoody','2010-01-01','2010-01-02','Start learning..'),(17,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(18,'DUTY',NULL,NULL,NULL),(19,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(20,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(21,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(22,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(23,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(24,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(25,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(26,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(27,'MSQL Test','1997-06-09','2017-10-20','BtoN'),(28,'Hi','0000-00-00','0000-00-00','hey'),(29,'Think','0000-00-00','0000-00-00','Think hard and get good'),(30,'animals','2017-06-10','0000-00-00','Databases'),(31,'Think','0000-00-00','0000-00-00','Think hard and get good'),(32,'Zay','1996-04-25','0000-00-00','WHats good'),(33,'DatabaseManagement','2010-01-01','2010-01-02','Start learning..'),(34,'Think','0000-00-00','0000-00-00','Think hard and get good'),(35,'Think','2017-10-10','2099-10-10','Think hard and get good'),(36,'Zay','1996-04-25','2000-01-12','WHats good'),(37,'Zay','1996-04-25','2000-01-12','WHats good'),(38,'SQL','2017-12-01','2020-01-12','Please'),(39,'Task 1','2010-01-01','2010-01-02','Description 1'),(40,'Task 2','2010-01-01','2010-01-02','Description 2'),(41,'Task 3','2010-01-01','2010-01-02','Description 3'),(42,'DatabaseManagement','2010-01-01','2010-01-02','Start learning..');
/*!40000 ALTER TABLE `tasks_1` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-11-12 18:54:42
