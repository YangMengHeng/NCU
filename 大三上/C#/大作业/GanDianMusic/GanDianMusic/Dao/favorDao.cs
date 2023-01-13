using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GanDianMusic
{
    class FavorDao
    {
        //添加歌曲
        static public int Addmusic(List<SongsInfo> list)
        {
            int value = 0;
            string sql = "insert into favor(filename, filepath, filesize, artist, album, albumImage, year, originname, duration, byterate, smallalbum) values" +
                "(" + "@fn, @fp, @fs, @art, @alb, @albI, @year, @ogn, @dur, @br, @sba)";
            foreach (SongsInfo music in list)
            {
                MySqlParameter[] sp = new MySqlParameter[11];
                sp[0] = new MySqlParameter("fn", music.FileName);
                sp[1] = new MySqlParameter("fp", music.FilePath);
                sp[2] = new MySqlParameter("fs", music.Filesize);
                sp[3] = new MySqlParameter("art", music.Artist);
                sp[4] = new MySqlParameter("alb", music.Album);
                sp[5] = new MySqlParameter("albI", music.AlbumImage);
                sp[6] = new MySqlParameter("year", music.Year);
                sp[7] = new MySqlParameter("ogn", music.OriginName);
                sp[8] = new MySqlParameter("dur", music.Duration);
                sp[9] = new MySqlParameter("br", music.ByteRate);
                sp[10] = new MySqlParameter("sba", music.SmallAblum);
                value = DBcon.NonQuery(sql, sp);
            }
            return value;
        }
        //查询
        public DataSet QueryAll()
        {
            string sql = "select * from favor";
            DataSet ds = DBcon.Query(sql, null);
            return ds;
        }
        //添加
        public int AddFavor(SongsInfo favor)
        {
            int value = 0;
            string sql = "insert into favor(filename, filepath, filesize, artist, album, albumImage, year, originname, duration, byterate, smallalbum) values"
                + "(" + "@fn, @fp, @fs, @art, @alb, @albI, @year, @ogn, @dur, @br, @sba)";
            MySqlParameter[] sp = new MySqlParameter[11];
            sp[0] = new MySqlParameter("fn", favor.FileName);
            sp[1] = new MySqlParameter("fp", favor.FilePath);
            sp[2] = new MySqlParameter("fs", favor.Filesize);
            sp[3] = new MySqlParameter("art", favor.Artist);
            sp[4] = new MySqlParameter("alb", favor.Album);
            sp[5] = new MySqlParameter("albI", favor.AlbumImage);
            sp[6] = new MySqlParameter("year", favor.Year);
            sp[7] = new MySqlParameter("ogn", favor.OriginName);
            sp[8] = new MySqlParameter("dur", favor.Duration);
            sp[9] = new MySqlParameter("br", favor.ByteRate);
            sp[10] = new MySqlParameter("sba", favor.SmallAblum);
            value = DBcon.NonQuery(sql, sp);
            return value;
        }

        static public void ClearFavor()
        {
            string sql = "truncate table favor;";

            DBcon.NonQuery(sql, null);
        }
    }
}
