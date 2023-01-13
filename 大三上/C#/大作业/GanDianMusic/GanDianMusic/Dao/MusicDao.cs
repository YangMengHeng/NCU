using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GanDianMusic
{
    class MusicDao
    {
        //添加歌曲
        static public int Addmusic(List<SongsInfo> list)
        {
            int value = 0;
            string sql = "insert into music(filename, filepath, filesize, artist, album, albumImage, year, originname, duration, byterate, smallalbum) values" +
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

        //根据歌曲名查询歌曲
        public DataSet QueryByName(string name)
        {
            string sql = "select * from music where filename like @Name";
            MySqlParameter[] sp = new MySqlParameter[1];
            sp[0] = new MySqlParameter("Name", "%" + name + "%");
            DataSet ds = DBcon.Query(sql, sp);
            return ds;
        }

        //根据歌手名查询歌曲
        public DataSet QueryByArtist(string name)
        {
            string sql = "select * from music where artist like @Singer";
            MySqlParameter[] sp = new MySqlParameter[1];
            sp[0] = new MySqlParameter("Singer", "%" + name + "%");
            DataSet ds = DBcon.Query(sql, sp);
            return ds;
        }

        public DataSet QueryAllMusic()
        {
            string sql = "select * from music";
            DataSet ds = DBcon.Query(sql, null);
            return ds;
        }
        //根据歌曲名删除歌曲
        public int DeleteByName(string name)
        {
            string sql = "delete from music where filename like @Name";
            MySqlParameter[] sp = new MySqlParameter[1];
            sp[0] = new MySqlParameter("Name", "%" + name + "%");
            return DBcon.NonQuery(sql, null);
        }

        internal static void Addmusic(SongsInfo music)
        {
            int value = 0;
            string sql = "insert into music(filename, filepath, filesize, artist, album, albumImage, year, originname, duration, byterate, smallalbum) values" +
                "(" + "@fn, @fp, @fs, @art, @alb, @albI, @year, @ogn, @dur, @br, @sba)";
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

        static public void ClearMusic()
        {
            string sql = "truncate table music;";

            DBcon.NonQuery(sql, null);
        }
    }
}
